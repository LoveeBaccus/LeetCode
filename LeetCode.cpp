// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

string longestCommonPrefix(vector<string>& strs) {

    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];

    bool flag = true; // possibility of common prefix
    string commonPrefix = "";
    int prefixLength = 0;
    while (flag) {
        prefixLength++;
        commonPrefix = strs[0].substr(0, prefixLength); //estabolish the prefix to be checked
         
        for (int i = 0; i < strs.size(); i++) { // check each word in the strs vector
            if (strs[i] == "") return "";
            // check to see if end of string

            if (commonPrefix != strs[i].substr(0, prefixLength)) { // the prefix does not work                    
                prefixLength--;
                commonPrefix = strs[0].substr(0, prefixLength); // put it back to the last successfull run
                flag = false;
            }
            else if (prefixLength == strs[i].length())
                flag = false;
        }

    }
    return commonPrefix;
}

void testingLongestCommonPrefix(void) {
    vector<string> test1 = {"flower", "flow", "flight"};
    vector<string> test2 = {"dog", "racecar", "car"};
    vector<string> test3 = { "a", "a" };
    vector<string> test4 = { "a", "b" };
    vector<string> test5 = { "" ,""};

    std::cout << "Input: [\"flower\", \"flow\", \"flight\"] \t Expected Output: \"fl\" \t Actual Output: \""<< longestCommonPrefix(test1)<< "\" \n";
    std::cout << "Input: {\"dog\", \"racecar\", \"car\"} \t Expected Output: \"\" \t Actual Output: \"" << longestCommonPrefix(test2) << "\"\n";
    std::cout << "Input: {\"dog\", \"racecar\", \"car\"} \t Expected Output: \"\" \t Actual Output: \"" << longestCommonPrefix(test2) << "\"\n";
    std::cout << "Input: {\"a\", \"a\"} \t Expected Output: \"a\" \t Actual Output: \"" << longestCommonPrefix(test3) << "\"\n";
    std::cout << "Input: {\"a\", \"b\"} \t Expected Output: \"\" \t Actual Output: \"" << longestCommonPrefix(test4) << "\"\n";
    std::cout << "Input: {\"\"\"\"} \t Expected Output: \"\" \t Actual Output: \"" << longestCommonPrefix(test5) << "\"\n";


}

int main()
{
    //testingPalindrome();
    testingLongestCommonPrefix();
    //dad is crazy
}


