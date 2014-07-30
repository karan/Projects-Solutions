import java.util.Scanner;
public class BinaryDecimal {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		String ans = null;
		do
		{
			System.out.print("1.Convert Decimal to Binary\n2.Convert Binary to Decimal\n" +
				"Enter an option : ");
			int op = in.nextInt();
			if(op == 1)
			{
				System.out.print("Enter the decimal number : ");
				int num = in.nextInt();
				System.out.println("The number in binary is " + decToBin(num));
			}
			else if(op == 2)
			{
				System.out.print("Enter the binary number : ");
				String num = in.next();
				System.out.println("The number in decimal is " + binToDec(num));
			}
			else
			{
				System.out.println("Wrong input entered");
			}
			System.out.print("Do you want to try again?(y/n) : ");
			ans = in.next();
		}while(ans.equalsIgnoreCase("y"));
	}

	private static long binToDec(String num) {
		long dec = 0;
		for(int i=num.length()-1;i>=0;i--)
		{
			long power = (long) Math.pow(2.0, num.length()-i-1);
			dec+=(power*(num.charAt(i)-'0'));
		}
		return dec;
	}

	private static String decToBin(int num) {
		
		String bin = "";
		do
		{
			bin = num%2 + bin;
			num = num/2;
		}while(num>0);
		return bin;
	}

}
