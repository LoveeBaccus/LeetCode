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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* newListNode(int val) {
    struct ListNode* temp = new ListNode;
    temp->val = val;
    temp->next = nullptr;
    return temp;
}

void printList(ListNode* temp) {
    cout << "[ ";
    while (temp->next != nullptr) {
        cout << temp->val << ", ";
        temp = temp->next;
    }
    cout << temp->val <<" ]\n";
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    // if list1 is null, then we just wanna return the other one
    if (!list1) {
        return list2;
    }
    // same thing for list1
    if (!list2) {
        return list1;
    }

    // process the smaller node first, and then call the recursive part with the larger one and the next val
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        // same thing but flipped
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

void testingMergeTwoLists(void) {
#pragma region TestCase1
    ListNode* h1 = newListNode(1);
    h1->next = newListNode(3);
    h1->next->next = newListNode(5);

    ListNode* h2 = newListNode(0);
    h2->next = newListNode(2);
    h2->next->next = newListNode(4);

    cout << "Input List1: ";
    printList(h1);
    cout << "Input List2: ";
    printList(h2);

    cout << "Expected Merged Output: [ 0, 1, 2, 3, 4, 5 ]\n";

    ListNode* h3 = mergeTwoLists(h1, h2);
    cout << "Actual Merged Output: \t";
    printList(h3);
#pragma endregion

#pragma region TestCase2
    ListNode* h4 = newListNode(4);
    h4->next = newListNode(5);
    h4->next->next = newListNode(10);

    ListNode* h5 = newListNode(3);
    h5->next = newListNode(12);
    
    cout << "Input List1: ";
    printList(h4);
    cout << "Input List2: ";
    printList(h5);

    cout << "Expected Merged Output: [ 3, 4, 5, 10, 12 ]\n";
    
    ListNode* h6 = mergeTwoLists(h4, h5);
    cout << "Actual Merged Output: \t";
    printList(h6);
#pragma endregion


}

int main()
{
    //testingPalindrome();
    //testingLongestCommonPrefix();
    testingMergeTwoLists();
    
}


