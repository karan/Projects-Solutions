__author__ = 'brian'


def reverse_str(s):
    result = ''
    for x in range(1, len(s)+1):
        result += s[x*-1]

    return result



