#include <iostream>
#include <iomanip>

using namespace std;


int main() 
{
  double earthWeight;
  double weight;
  int x;

  std::cout << "Please enter your current earth weight: ";
  std::cin >> earthWeight;

  std::cout << "These are the planets that have boxing tournaments: ";

  std::cout << "\n 1. Venus";
  std::cout << "\n 2. Earth";
  std::cout << "\n 3. Mars";
  std::cout << "\n 4. Jupiter";
  std::cout << "\n 5. Saturn";
  std::cout << "\n 6. Uranus";
  std::cout << "\n 7. Neptune";


  std::cout << "Which planet are you visiting?";
  std::cin >> x;

  switch (x)
  {
    case 1:
        weight = earthWeight *0.78;
        std::cout << "Your weight is: " << weight;
        break;

    case 2:
        weight = earthWeight;
        std::cout << "Your weight is: " << weight;
        break;

    case 3:
        weight = earthWeight *0.39;
        std::cout << "Your weight is: " << weight;
        break;

    case 4:
        weight = earthWeight *2.65;
        std::cout << "Your weight is: " << weight;
        break;

    case 5:
        weight = earthWeight *1.17;
        std::cout << "Your weight is: " << weight;
        break;

    case 6:
        weight = earthWeight *1.05;
        std::cout << "Your weight is: " << weight;
        break;

    case 7:
        weight = earthWeight *1.23;
        std::cout << "Your weight is: " << weight;
        break;

    default:
        std::cout << "There isn't a planet on the menu with this number.";
  
    break;
  }
}