/*
 * This file contains 2 sorting implementations: Bubble sort and Merge sort.
 * The implementations were made generic so that it can be used with most
 * data types. Written in C++11 standard.
 *
 * Author: Yasaswy Kota.
 */

#include <iostream>
#include <vector>
#include <random>

#define COUNT 10 /*The count of numbers to work on*/

/*
 * Used for printing the vector to stdout.
 */
template<typename T>
void print_numbers(std::vector<T> numbers)
{
    for( auto i = numbers.begin(); i != numbers.end(); i = std::next(i, 1))
        std::cout << *i << ' ';
    std::cout << std::endl;
}

/*
 * Sorts a vector of given type T using bubble sort.
 * Sorts in O(n^2) time complexity and O(1) space complexity.
 */
template<typename T>
std::vector<T> bubble_sort(std::vector<T> numbers)
{
    int x, y;
    double temp;
    for(x = 0; x < numbers.size() - 1; x++)
    {
        for(y=0; y < numbers.size() - x - 1; y++)
        {
            if(numbers[y] > numbers[y+1])
            {
                temp = numbers[y];
                numbers[y] = numbers[y+1];
                numbers[y+1] = temp;
            }
        }
    }

    return numbers;
}

/*
 * Sorts a vector of given type T using merge sort.
 * Sorts in O(nlogn) time complexity and O(n) space complexity.
 *
 * This function merges the partitioned vectors into a single, sorted vector.
 */
template <typename T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right)
{
    std::vector<T> result;
    unsigned left_index = 0, right_index = 0;
 
    while(left_index < left.size() && right_index < right.size())
    {
        if(left[left_index] < right[right_index])
        {
            result.push_back(left[left_index]);
            left_index++;
        }
        else
        {
            result.push_back(right[right_index]);
            right_index++;
        }
    }
 
    while(left_index < left.size())
    {
        result.push_back(left[left_index]);
        left_index++;
    }
 
    while(right_index < right.size())
    {
        result.push_back(right[right_index]);
        right_index++;
    }
 
    return result;
}

/*
 * This function partitions the given vector until each of them have only
 * a single element in them.
 */
template <typename T>
std::vector<T> mergeSort(std::vector<T> numbers)
{
   if (numbers.size() <= 1)
      return numbers;
 
   int middle = numbers.size() / 2;

   std::vector<T> left(numbers.begin(), numbers.begin() + middle);
   std::vector<T> right(numbers.begin() + middle, numbers.end());
 
   left = mergeSort(left);
   right = mergeSort(right);
 
   return merge(left, right);
}

int main(int argc, char const *argv[])
{
    std::vector<double> numbers;

    // Generate random numbers and add it to the vector.
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(0.1,10);

    for(int i = 0; i < COUNT; i++)
        numbers.push_back(distribution(generator));

    std::cout << "Numbers before sorting" << std::endl;
    print_numbers(numbers);
    std::cout << std::endl;

    std::cout<< "After bubble sort." << std::endl;
    print_numbers(bubble_sort(numbers));
    std::cout << std::endl;

    std::cout<< "After merge sort. "<< std::endl;
    print_numbers(mergeSort(numbers));

    return 0;
}