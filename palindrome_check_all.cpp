#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

// Determining Integer
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

bool isPalindrome(string inpStr) {

    if (isNumber(inpStr)) {        // Handling Integer
        long long int origNum = stoll(inpStr, nullptr, 10);  // Temporary variable for assigning long long int type variable
        long long int revNum = 0, tmpOrig = 0;
        int remainder;

        tmpOrig = origNum;

        while( tmpOrig != 0 )
        {
            remainder = tmpOrig % 10;
            revNum = revNum * 10 + remainder;
            tmpOrig = tmpOrig / 10;
        }

        if (origNum == revNum) {
            return true;
        } else {
            return false;
        }
    }

    // Handling String
    int n = inpStr.length() - 1;
    int l = 0;

    transform(inpStr.begin(), inpStr.end(), inpStr.begin(), ::tolower); // Converting lower case to handle in efficient way

    char char_array[n+1];
    strcpy(char_array, inpStr.c_str());

    // Keep comparing characters while they are same
    while (n > l)
    {
        if (char_array[l++] != char_array[n--])
        {
            return false;
        }
    }

    return true;
}

// Main function
int main()
{
    string str; // Variable to take input

    cout << "ENTER NUMBER TO CHECK PALINDROME....." << endl;
    getline(cin, str);   // Taking input as line

    if (str.length() > 0) {

        cout << "YOUR INPUT:: " << str << endl;
        cout << " " << endl;

        if (isPalindrome(str)) {
            cout << str << " ::Palindrome."  << endl;
        } else {
            cout << str << " ::NOT Palindrome." << endl;
        }
    } else {
        cout << "NO INPUT PROVIDED" << endl;
    }
    return 0;
}
