#ifndef PASSWORD_VALIDATOR_H
#define PASSWORD_VALIDATOR_H

#include <string>
#include <vector>

using namespace std;

// Function declarations
bool hasUppercase(const string &password);
bool hasLowercase(const string &password);
bool hasDigit(const string &password);
bool hasSymbol(const string &password);
bool hasMinLength(const string &password, int minLength);
vector<string> validatePassword(const string &password);

#endif // PASSWORD_VALIDATOR_H
