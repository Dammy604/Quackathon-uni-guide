#include <iostream>
using namespace std;

class Robot {
public:
    int batteries;  // a property of the robot
    Robot() {  // This is the constructor
        batteries = 100;  // We set the batteries to full when the robot is created
        cout << "Robot is ready to go!" << endl;
    }
};

int main() {
    Robot r;  // This creates the robot, and the constructor runs automatically
    cout << "Robot batteries: " << r.batteries << endl;
    return 0;
}
