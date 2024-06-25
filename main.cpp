#include <iostream>

using namespace std;


class Robot {
    public:
    
    string RobotType;
    void GetRobotType() { cout << "Geekname is:" << RobotType; }
    void SetRobotType(string robotType) {RobotType = robotType; }

};

class Moving:public 
Robot {
    public:
    string Name;
    void GetRobotName() { cout << "Geekname is:" << Name; }
    void SetRobotName(string name) {this->Name = name; }
    void move(){}

};

class Seeing:public 
Robot {
    public:
    string Name;
    void GetRobotName() { cout << "Geekname is:" << Name; }
    void SetRobotName(string name) {Name = name; }
    void look(){}
};

class Shooting:public 
Robot {
    public:
    string Name;
    void GetRobotName() { cout << "Geekname is:" << Name; }
    void SetRobotName(string name) {Name = name; }
    void Shoot(){}
};

class Steping:public 
Robot {
    public:
    string Name;
    void GetRobotName() { cout << "Geekname is:" << Name; }
    void SetRobotName(string name) {Name = name; }
    void Stomp(){}
};

class RoboCop: public Shooting , public Seeing , public Moving{

};

class Terminator: public Seeing , public Moving , public Steping{

};

class TerminatorRobocop: public Seeing , public Moving , public Steping , public Shooting{

};

class BlueThunder: public Shooting{

};

class MadBot: public Shooting{

};

class RoboTank: public Shooting{

};

class UltimateRobot: public Shooting , public Moving , public Steping, public Seeing{

};

int main() {

    Moving newRobot1;

    cout << newRobot1.RobotType+ " check type first time \n";
    newRobot1.SetRobotType("Type 1");
    cout << newRobot1.RobotType+ " check type second time \n";

    cout << newRobot1.Name+ " check name first time \n";
    newRobot1.SetRobotName("Behnaz");
    cout << newRobot1.Name+ " check name second time \n";

    return 0;
}