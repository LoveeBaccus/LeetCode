// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
*/

#include <iostream>
bool isPalindrome(int x) {
    bool flag = false;
    int reversed = 0;

    // corner cases: negative and if it ends in a 0, ex 10
    if (x < 0 || (x > 0 && x % 10 == 0)) {
        flag = false;
    }
    else {
        while (reversed < x) {
            //adds the rightmost digit to reversed
            reversed = reversed * 10 + x % 10;
            //removes the rrightmost digit from x
            x /= 10;
        }

        //checks for quality
        //remember that a num with an odd number of digits will be wonky
        if (x == reversed || x == reversed / 10) {
            flag = true;
        }
    }

    return flag;
}

void testingPalindrome(void) {
    std::cout << "input: 121\texpected output: true\tactual output: " << (isPalindrome(121) ? "true" : "false") << "\n";
    std::cout << "input: 123\texpected output: false\tactual output: " << (isPalindrome(123) ? "true" : "false") << "\n";
    std::cout << "input: 10\texpected output: false\tactual output: " << (isPalindrome(10) ? "true" : "false") << "\n";
}

int main()
{
    testingPalindrome();
    

}


