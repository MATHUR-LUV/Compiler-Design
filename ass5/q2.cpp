#include <iostream>
#include <string>
using namespace std;

// Function to check if the string matches a*ba*
bool matchesAStarBAStar(const string& input) {
    size_t i = 0;
    // Match a*
    while (i < input.length() && input[i] == 'a') {
        i++;
    }
    // Match b
    if (i < input.length() && input[i] == 'b') {
        i++;
    } else {
        return false;
    }
    // Match a*
    while (i < input.length() && input[i] == 'a') {
        i++;
    }
    return i == input.length();
}

// Function to check if the string matches b*ab*
bool matchesBStarABStar(const string& input) {
    size_t i = 0;
    // Match b*
    while (i < input.length() && input[i] == 'b') {
        i++;
    }
    // Match a
    if (i < input.length() && input[i] == 'a') {
        i++;
    } else {
        return false;
    }
    // Match b*
    while (i < input.length() && input[i] == 'b') {
        i++;
    }
    return i == input.length();
}

// Function to check if the string matches (ab + ba)
bool matchesABOrBA(const string& input) {
    return input == "ab" || input == "ba";
}

// Function to check if the string matches (a + ab)
bool matchesAOrAB(const string& input) {
    return input == "a" || input == "ab";
}

// Function to recursively check the full expression
bool matchesFullExpression(const string& input) {
    // Base cases for sub-patterns
    if (matchesAStarBAStar(input) || matchesBStarABStar(input)) {
        return true;
    }

    // Match (ab + ba)*(a + ab)
    for (size_t i = 0; i < input.length(); ++i) {
        string firstPart = input.substr(0, i);
        string lastPart = input.substr(i);

        if ((firstPart.empty() || matchesABOrBA(firstPart)) && matchesAOrAB(lastPart)) {
            return true;
        }
    }

    return false;
}

// Main function
int main() {
    string testString;
    cout << "Enter a string to test against the regex: ";
    cin >> testString;

    if (matchesFullExpression(testString)) {
        cout << "The string matches the regular expression.\n";
    } else {
        cout << "The string does not match the regular expression.\n";
    }

    return 0;
}
