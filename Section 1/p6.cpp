#include <iostream>
#include <unordered_map>
#include <cctype>
#include <locale>

using namespace std;

// Function to check if a character is a letter or a digit
bool isValidChar(char c) {
    return isalnum(c);
}

// Function to find the most frequent character
pair<char, int> findMaxOccurrence(const string &input) {
    unordered_map<char, int> charCount;
    int maxCount = 0;
    char maxChar = '\0';

    for (char c : input) {
        if (isValidChar(c)) {
            charCount[c]++;

            if (charCount[c] > maxCount) {
                maxCount = charCount[c];
                maxChar = c;
            }
        }
    }

    return {maxChar, maxCount};
}

int main() {
    string input = "Hello, world!";

    pair<char, int> result = findMaxOccurrence(input);

    if (result.second > 0) {
        cout << "Character: '" << result.first << "', Occurrence: " << result.second << endl;
    } else {
        cout << "No valid characters found in the string." << endl;
    }

    return 0;
}
