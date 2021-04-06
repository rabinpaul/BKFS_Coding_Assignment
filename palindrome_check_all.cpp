#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

// Determining Integer
bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

int oneDigitExists(int num)
{
    return (num < 10 && num >= 0);
}

bool isPalindromUtil(int num, int* dupN)
{
   if (oneDigitExists(num))
        return (num == (*dupN) % 10);

    if (!isPalindromUtil(num / 10, dupN))
        return false;

    *dupN /= 10;

    return (num % 10 == (*dupN) % 10);
}
// Palindrome Checking on Integer value
int isPalindromInt(int num)
{
    if (num < 0)
        num = -num;
    int* dupNumber = new int(num);

    return isPalindromUtil(num, dupNumber);
}

bool isPalindromeChk(char str[], int s, int e)
{
	if (s == e)
	return true;

	if (str[s] != str[e])
	return false;

	if (s < e + 1)
	return isPalindromeChk(str, s + 1, e - 1);

	return true;
}

// Palindrome Checking on String
bool isPalindromStr(char str[])
{
	int n = strlen(str);

	if (n == 0)
		return true;

	return isPalindromeChk(str, 0, n - 1);
}

// Checking Input and start determining for Palindrome
void check_input_n_determine(string str1) {
      if (isNumber(str1)) {        // Handling Integer
            cout << "Input is an Integer." << endl;
            int numCheckPal = stoi(str1);  // Temporary variable for assigning iput variable

            isPalindromInt(numCheckPal) ? printf("%d: Palindrome Number\n", numCheckPal) : printf("%d: NOT Palindrome Number\n", numCheckPal);
        }
        else {     // Handling String
            cout << "Input is a String."  << endl;
            int n = str1.length();

            char orig_array[n+1];
            strcpy(orig_array, str1.c_str());

            transform(str1.begin(), str1.end(), str1.begin(), ::tolower); // Converting lower case to handle in efficient way

            char char_array[n+1];
            strcpy(char_array, str1.c_str());

            isPalindromStr(char_array) ? printf("%s: Palindrome String\n", orig_array) : printf("%s: NOT Palindrome String\n", orig_array);
      }
}

// Main function
int main()
{
    string str; // Variable to take input

    cout << "Enter Input to check Palindrome" << endl;
    getline(cin, str);   // Taking input as line

    if (str.length() > 0) {
        cout << "VALID INPUT PROVIDED" << endl;
        check_input_n_determine(str);  // Determining whether input is a Integer or String
    } else {
        cout << "NO INPUT PROVIDED" << endl;
    }
    return 0;
}
