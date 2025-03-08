#include "password_validator.h"
#include <iostream>

using namespace std;

int main() {
    string password;

    cout << "Enter a password: ";
    cin >> password;

    // Validate the password
    vector<string> validationResults = validatePassword(password);

    // Display results
    cout << "\nPassword Validation Results:\n";
    for (const auto &result : validationResults) {
        cout << result << endl;
    }

    // Check if the password is valid
    if (validationResults.size() == 5 &&
        validationResults[0].find("✅") != string::npos &&
        validationResults[1].find("✅") != string::npos &&
        validationResults[2].find("✅") != string::npos &&
        validationResults[3].find("✅") != string::npos &&
        validationResults[4].find("✅") != string::npos) {
        cout << "\nPassword is valid!" << endl;
    } else {
        cout << "\nPassword is invalid. Please meet all criteria." << endl;
    }

    return 0;
}
