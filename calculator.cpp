#include <iostream>

using namespace std;

class Calculator{

    public:
    
    int addition(int &number1,int &number2){
        return number1 + number2;
    }

    int subtraction(int &number1,int &number2){
        return number1 - number2;
    }
    int multiplication(int &number1,int &number2){
        return number1 * number2;
    
    }

    float division(int &number1, int &number2){
        if (number2 == 0)
        {
            cout << "Number 2 is 0 and is therefore invalid! Please write a non-zero number \n" << endl;
            return 0;

        } else 
        {
            return number1 / number2;
        }
    };
    
    int remainder(int &number1,int &number2){
        return number1 % number2;
    }

    int sumOfSquares(int &number1, int &number2)
    
    {
        return (number1 * number1) + (number2 * number2);
    }

    int power(int &number1, int &number2) 
    {
        return number1 ^ number2;
    }
};


int main(){
    //menu showing
    // create switch case
    //make calculator class
    //creating 6

    int num1;
    int num2;
    int choice;
    int result;

    Calculator calc;

    cout << "DAMI'S CALCULATOR" << "/n" << endl;

    cout << "Enter the first number" << endl;
    cin >> num1;

    cout << "Enter the second number" << endl;
    cin >> num2;

    cout << "Menu/n" << endl;
    cout << "1. Sum \n";
    cout << "2. Difference \n";
    cout << "3. Product \n";
    cout << "4. Quotient \n";
    cout << "5. Remainder \n";
    cout << "6. Sum Of Squares \n";
    cout << "7. Power \n";


    cout << "Enter your choice from 1 to 7";
    cin >> choice;

    switch (choice)
    {
    case 1: 
        calc.addition(num1,num2);
    break;

    case 2: 
        calc.subtraction(num1,num2);
    break;

    case 3: 
        calc.multiplication(num1,num2);
    break;
    
    case 4: 
        calc.division(num1,num2);
    break;

    case 5: 
        calc.remainder(num1,num2);
    break;

    case 6: 
        calc.sumOfSquares(num1,num2);
    break;

    case 7: 
        calc.power(num1,num2);
    break;

    default: 
        cout << "Invalid option. Please enter a number from 1 to 7\n";
    break;
    }



    

    


    
}
