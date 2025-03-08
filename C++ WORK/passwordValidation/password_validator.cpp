#include "password_validator.h"
#include <regex>

using namespace std;

// Function to check for at least one uppercase letter
bool hasUppercase(const string &password) {
    return regex_search(password, regex("[A-Z]"));
}

// Function to check for at least one lowercase letter
bool hasLowercase(const string &password) {
    return regex_search(password, regex("[a-z]"));
}

// Function to check for at least one digit
bool hasDigit(const string &password) {
    return regex_search(password, regex("\\d"));
}

// Function to check for at least one symbol
bool hasSymbol(const string &password) {
    return regex_search(password, regex("[@$!%*?&#]"));
}

// Function to check if password meets the minimum length requirement
bool hasMinLength(const string &password, int minLength) {
    return password.length() >= minLength;
}

// Function to validate the password and return the results
vector<string> validatePassword(const string &password) {
    vector<string> results;

    if (hasUppercase(password))
        results.push_back("Contains at least one uppercase letter: yes");
    else
        results.push_back("Contains at least one uppercase letter: no");

    if (hasLowercase(password))
        results.push_back("Contains at least one lowercase letter: yes");
    else
        results.push_back("Contains at least one lowercase letter: no");

    if (hasDigit(password))
        results.push_back("Contains at least one number: yes");
    else
        results.push_back("Contains at least one number: no");

    if (hasSymbol(password))
        results.push_back("Contains at least one symbol (@$!%*?&#): yes");
    else
        results.push_back("Contains at least one symbol (@$!%*?&#): no");

    if (hasMinLength(password, 8))
        results.push_back("Has at least 8 characters: yes");
    else
        results.push_back("Has at least 8 characters: no");

    return results;
}
