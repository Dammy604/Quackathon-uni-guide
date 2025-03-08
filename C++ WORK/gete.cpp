#include <iostream>

// Square a number using a global variable
int num = 5;

int square(int num) {
    return num * num;
}

int main() {
    std::cout << "The square of " << num << " is: " << square(num) << std::endl;
    return 0;
}
