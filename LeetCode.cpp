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
#include <stack>
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

    // I should write the codde to verify both sublists are sorted prior to merging them
    // I could also add in negative numbers to make sure that works
    // other corner cases could consider duplicate values?
}

int romanToInt(string s) {
    int total = 0;
    vector<int> input = {};

    //convert the given string to ints stored in a vector
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            input.push_back(1);
        }
        else if (s[i] == 'V') {
            input.push_back(5);
        }
        else if (s[i] == 'X') {
            input.push_back(10);
        }
        else if (s[i] == 'L') {
            input.push_back(50);
        }
        else if (s[i] == 'C') {
            input.push_back(100);
        }
        else if (s[i] == 'D') {
            input.push_back(500);
        }
        else if (s[i] == 'M') {
            input.push_back(1000);
        }
    }
    
    int cur = 0;
    int next = 1;
    while (next < input.size()) {

        if (input[cur] >= input[next]) { // as is the case with III or 
            total += input[cur];
            // just increment one because we didn't add next to total yet
            next++;
            cur++;

        }
        else { //as is the case with IV (4)
           // then we want to subtract left from right --> like 5 - 1 = 4 when IV
           // then add that number to the total
            total += input[next] - input[cur];
            // we want to jump two because those have both been processed 
            next += 2;
            cur += 2;

        }
    }
    if (cur == input.size() - 1) {
        total += input[cur];
    }
    return total;
}

void testingRomanToInt(void) {
    cout << "Input: III\tExpected Output: 3\tActual Output: " << romanToInt("III") << "\n";
    cout << "Input: LVIII\tExpected Output: 58\tActual Output: " << romanToInt("LVIII") << "\n";
    cout << "Input: MCMXCIV\tExpected Output: 1994\tActual Output: " << romanToInt("MCMXCIV") << "\n";
    
    cout << "Input: MCMLXVIII\tExpected Output: 1968\tActual Output: " << romanToInt("MCMLXVIII") << "\n";
    cout << "Input: ***\tExpected Output: 99999\tActual Output: " << romanToInt("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMCMXCIX") << "\n";

    cout << "Input: ABC\tExpected Output: ERROR\tActual Output: " << romanToInt("ABC") << "\n";
    cout << "Input: 123\tExpected Output: ERROR\tActual Output: " << romanToInt("123") << "\n";
    cout << "Input: iii\tExpected Output: ERROR\tActual Output: " << romanToInt("iii") << "\n";
    cout << "Input: \"\"\tExpected Output: ERROR\tActual Output: " << romanToInt("") << "\n";
    // cout << "Input: NULL\tExpected Output: ERROR\tActual Output: " << romanToInt(NULL) << "\n"; crashed 

}

bool isValidParenthesis(string s) {
    // if its an empty string, we can't do anything
    if (s.length() == 0) {
        cout << "Empty input string\n";
        return false;
    }

    stack<char> parenStack;
    // for each character in the input string
    for (int i = 0; i < s.length(); i++) {
        // check if it is an open paren
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            parenStack.push(s[i]);
        }
        // or a close parent
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            // if its a close paren, but there is no buddy on the stack, then we know it was mismatched
            if (parenStack.empty()) {
                return false;
            }

            // for each style, check for its pair
            if (s[i] == ')' && parenStack.top() == '(') {
                parenStack.pop();
            }
            else if (s[i] == ']' && parenStack.top() == '[') {
                parenStack.pop();
            }
            else if (s[i] == '}' && parenStack.top() == '{') {
                parenStack.pop();
            }
            // if it didn't have a pair, we want to push it so that the stack won't be empty at the end
            // we could just return false here
            else {
                return false;
                parenStack.push(s[i]);
                
            }
        }
        else {
            std::cout << "non paren character\n";
            parenStack.push(s[i]);
        }
    }
    if (parenStack.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void testingIsValidParenthesis(void) {
    std::cout << "input: ()\texpected output: true\tactual output: " << (isValidParenthesis("()") ? "true" : "false") << "\n";
    std::cout << "input: ()[]{}\texpected output: true\tactual output: " << (isValidParenthesis("()[]{}") ? "true" : "false") << "\n";
    std::cout << "input: )(][}{\texpected output: false \tactual output: " << (isValidParenthesis(")(][}{") ? "true" : "false") << "\n";
    std::cout << "input: (]\texpected output: false\tactual output: " << (isValidParenthesis("(]") ? "true" : "false") << "\n";
    std::cout << "input: \"\"\texpected output: false\tactual output: " << (isValidParenthesis("") ? "true" : "false") << "\n";
    std::cout << "input: ([])\texpected output: true\tactual output: " << (isValidParenthesis("([])") ? "true" : "false") << "\n";
    std::cout << "input: (())\texpected output: true\tactual output: " << (isValidParenthesis("(())") ? "true" : "false") << "\n";

    std::cout << "input: ABC\texpected output: false\tactual output: " << (isValidParenthesis("ABC") ? "true" : "false") << "\n";

}

vector<int> removeDuplicates(vector<int>& nums) {
    // since the input array is sorted, its not tooooo tricky
    // we should verify that it is sorted when I do it on VS

    if (nums.size() == 0) {
        return {};
    }

    int ind = 1;
    for (int i = 1;i < nums.size();i++) {

        if (nums[i] != nums[i - 1]) {
            nums[ind] = nums[i];
            ind++;
        }
    }
    nums.erase(nums.begin() + ind, nums.end());
    return nums;
}

void printVector(vector<int> nums) {
    if (nums.size() == 0) {
        cout << "{ }";
    }
    else {
        cout << "{ ";
        int i = 0;
        for (; i < nums.size() - 1; i++) {
            cout << nums[i] << ", ";
        }
        cout << nums[i] << " }\n";
    }

}

void testingRemoveDuplicates(void) {
    vector <int> input1 = { 1,1,2 };
    vector<int> actualOutput1 = removeDuplicates(input1);

    cout << "Input: { 1, 1, 2 }\nExpected Output:\t{ 1, 2 }\nActual Output:\t\t"; 
    printVector(actualOutput1);

    vector <int> input2 = { 0,0,1,1,1,2,2,3,3,4 };
    vector<int> actualOutput2 = removeDuplicates(input2);

    cout << "Input: { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }\nExpected Output:\t{ 0, 1, 2, 3, 4 }\nActual Output:\t\t";
    printVector(actualOutput2);

    vector <int> input3 = {};
    vector<int> actualOutput3 = removeDuplicates(input3);

    cout << "Input: { }\nExpected Output:\t{ }\nActual Output:\t\t";
    printVector(actualOutput3);

}

int removeElement(vector<int>& nums, int val) {

    int k = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            // if it is a good value, we want to keep it in the final and therefore not overwrite it, so we want to increment k
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

void printKelements(int k, vector<int> nums) {
    if (k == 0) {
        cout << "{ }";
    }
    else {
        cout << "{ ";
        int i = 0;
        for (; i < k - 1; i++) {
            cout << nums[i] << ", ";
        }
        cout << nums[i] << " }\n";
    }
}

void testingRemoveElement(void) {
    vector<int> test = { 1,1,2 };
    int target = 1;
    int k;
    cout << "Input Vector: { 1, 1, 2 } \nInput Target: 1\n";
    cout << "Expected Output Vector:\t{ 2 }\n";

    k = removeElement(test, target);
    cout << "Actual Output Vector: \t";
    printKelements(k, test);

    cout << "\n";

    test = { 0,1,2,2,3,0,4,2 };
    target = 2;
    cout << "Input Vector: { 0, 1, 2, 2, 3, 0, 4, 2 } \nInput Target: 2\n";
    cout << "Expected Output Vector:\t{ 0, 1, 3, 0, 4 }\n";

    k = removeElement(test, target);
    cout << "Actual Output Vector: \t";
    printKelements(k, test);

    cout << "\n";

    test = { 0,1,2,3,4,5,6 };
    target = -1;
    cout << "Input Vector: { 0, 1, 2, 3, 4, 5, 6 } \nInput Target: -1\n";
    cout << "Expected Output Vector:\t{ 0, 1, 2, 3, 4, 5, 6 }\n";

    k = removeElement(test, target);
    cout << "Actual Output Vector: \t";
    printKelements(k, test);

    cout << "\n";

    test = { 0, 0, 0, 0, 0 };
    target = 0;
    cout << "Input Vector: { 0, 0, 0, 0, 0 } \nInput Target: 0\n";
    cout << "Expected Output Vector:\t{ }\n";

    k = removeElement(test, target);
    cout << "Actual Output Vector: \t";
    printKelements(k, test);
}

int needleHaystack(string haystack, string needle) {
    if (needle == "") {
        return 0;
    }
    int found = haystack.find(needle);
    if (found == string::npos) {
        return -1;
    }

    return found;
}

void testingNeedleHaystack(void) {
    // haystack = hello, needle = ll, output = 2
    cout << "Input: haystack: \"hello\" needle: \"ll\"\n";
    cout << "Expected Output: 2\n";
    cout << "Actual Output: \t" << needleHaystack("hello", "ll") << "\n\n";

    // haystack = aaaaaaaaa, needle = bba, output = -1
    cout << "Input: haystack: \"aaaaaaaaa\" needle: \"bba\"\n";
    cout << "Expected Output: -1\n";
    cout << "Actual Output: \t" << needleHaystack("aaaaaaaaa", "bba") << "\n\n";

    // haystack = "", needle = "", output = 0
    cout << "Input: haystack: \"\" needle: \"\"\n";
    cout << "Expected Output: 0\n";
    cout << "Actual Output: \t" << needleHaystack("", "") << "\n\n";

}

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    int mid = 0;

    while (left < right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            right = mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
    }
    return left;
}

void testingSearchInsert(void) {
    cout << "Input: nums = [ 1, 3, 5, 6 ], target = 5\n";
    cout << "Expected Output: 2\n";
    vector<int> nums = { 1, 3, 5, 6 };
    cout << "Actual Output: " << searchInsert(nums, 5) << "\n";
}

// merge two strings to create password
// clothing featured item -- list of strings, counts how many times each item was bought then finds the best selling
// water levels trailing difference 
// parenthesis ticket items -- same as the above, so probably not worth repeating
// count occurances of each value in the array


int main()
{
    //testingPalindrome();
    //testingLongestCommonPrefix();
    //testingMergeTwoLists();
    //testingRomanToInt();
    //testingIsValidParenthesis();
    //testingRemoveDuplicates();
    //testingRemoveElement();

    //testingNeedleHaystack();
    testingSearchInsert();
}


