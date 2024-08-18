#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

// Function to removing non-alphanumeric characters and converting to lowercase
string normalizeString(const string &str) {
    string normalized;
    for (char c : str) {
        if (isalnum(c)) {
            normalized += tolower(c);
        }
    }
    return normalized;
}

// Function to check if two strings are anagrams of each other
bool areAnagrams(const string &str1, const string &str2) {
    string normStr1 = normalizeString(str1);
    string normStr2 = normalizeString(str2);

    // If the lengths are different, they can't be anagrams
    if (normStr1.length() != normStr2.length()) {
        return false;
    }

    // Count characters in the first string
    unordered_map<char, int> charCount;
    for (char c : normStr1) {
        charCount[c]++;
    }

    // Compare character counts with the second string
    for (char c : normStr2) {
        if (charCount.find(c) == charCount.end()) {
            return false; // Character in str2 not found in str1
        }
        if (--charCount[c] < 0) {
            return false; // More occurrences of character in str2 than in str1
        }
    }

    return true; 
}

int main() {
    string str1, str2;

    cout<<"Enter first string: ";
    getline(cin,str1);

    cout<<"Enter second string: ";
    getline(cin,str2);

    cout << "Are "<<str1<<" and "<<str2<<" anagrams: " << (areAnagrams(str1, str2) ? "true" : "false") << endl;

    return 0;
}
