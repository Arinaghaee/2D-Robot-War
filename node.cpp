#include <iostream>
#include <queue>
#include <list>

using namespace std;

struct Cordinate { int x; int y;};


class Node{
    public:
    int data;
    string occupyBy;
    bool occupied;
    Cordinate cordinate;
    Node *next;
};

void push(Node* * head_ref, int new_data, struct Cordinate cordinate)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
    new_node->cordinate = cordinate;
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

int sizeList(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
};

bool searchLinkedList(Node* head, int x, int y) {
    // Traverse the Linked List
    while (head != nullptr) {
        // Check if the current node's data matches the target value
        if (head->cordinate.x == x && head->cordinate.y == y) {

            cout<< "("<< head->cordinate.x<<","<<head->cordinate.y<<")"<<endl;
            return true;  // Value found
        }
        // Move to the next node
        head = head->next;
    }
    
    return false;  // Value not found
};

int buildList(Node** head, int row, int column){
    int size = row * column;
    int x = 1;
    int y = 1;
    bool rowIsFull = false;
    for(int i = 0; i< size; i++){
            Cordinate c;
            c.x = x;
            c.y = y;
            push(head, i, c);
            if (x == column){
                rowIsFull  = true;
            }
            if(rowIsFull == true){
              y++;
              x = 0;
              rowIsFull = false;
            }
            x++;
    }

    return 1;
};

void printBoard(Node* head){
    string board = "";
    cout << endl;
    while (head != nullptr) {
        // Check if the current node's data matches the target value
        bool nextRow = false;
        if (head->cordinate.x == 1){
            nextRow = true;
        }
        if (head->occupied == true){
            board = " x" + board;
        }else{
            board = " O" + board;
        }
        if(nextRow == true){
            cout << board;
            cout << endl;
            board = "";
            nextRow = false;
        }
        // cout << head->cordinate.x << head->cordinate.y << "O" << endl;
        // Move to the next node
        head = head->next;
    }


}

bool setLinkedList(Node* head, int x, int y) {
    // Traverse the Linked List
    while (head != nullptr) {
        // Check if the current node's data matches the target value
        if (head->cordinate.x == x && head->cordinate.y == y) {
            head->occupied = true;
            head->occupyBy = "MadBot";
            return true;  // Value found
        }
        // Move to the next node
        head = head->next;
    }
    
    return false;  // Value not found
};

bool resetLinkedList(Node* head, int x, int y) {
    // Traverse the Linked List
    while (head != nullptr) {
        // Check if the current node's data matches the target value
        if (head->cordinate.x == x && head->cordinate.y == y) {
            head->occupied = false;
            head->occupyBy = "";
            return true;  // Value found
        }
        // Move to the next node
        head = head->next;
    }
    
    return false;  // Value not found
};





int move(Node* head, Cordinate startCordinate){
    const char* direction[8] = {"upLeft", "up", "upRight", "left", "right", "downLeft", "down", "rightDown"};
    int xtemp = startCordinate.x;
    int ytemp = startCordinate.y;
    for(int i = 0; i < 8; i++)
    {resetLinkedList(head, xtemp, ytemp);
        if(strcmp(direction[i], "upLeft") == 0){
            xtemp  = xtemp - 1;
            ytemp  = ytemp + 1;
        }else if(strcmp(direction[i], "up") == 0){
            xtemp  = xtemp;
            ytemp  = ytemp + 1;
        }else if(strcmp(direction[i], "upRight") == 0){
            xtemp  = xtemp + 1;
            ytemp  = ytemp + 1;
        }else if(strcmp(direction[i], "left") == 0){
            xtemp  = xtemp - 1;
            ytemp  = ytemp;
        }else if(strcmp(direction[i], "right") == 0){
            xtemp  = xtemp + 1;
            ytemp  = ytemp;
        }else if(strcmp(direction[i], "downLeft") == 0){
            xtemp  = xtemp -1;
            ytemp  = ytemp -1;
        }else if(strcmp(direction[i], "down") == 0){
            xtemp  = xtemp;
            ytemp  = ytemp -1;
        }else if(strcmp(direction[i], "rightDown") == 0){
            xtemp  = xtemp + 1;
            ytemp  = ytemp - 1;
        }
        setLinkedList(head, xtemp, ytemp);
        cout << direction[i] << endl;
        printBoard(head);
    }
return 1;
}

class Robot {
    public:
    string Name;
    Cordinate cordinate;
    string RobotType;
    void GetRobotType() { cout << "Geekname is:" << RobotType; }
    void SetRobotType(string robotType) {RobotType = robotType; }

};

class Moving:public 
Robot {
    public:
    // void GetRobotName() { cout << "Geekname is:" << Name; }
    // void SetRobotName(string name) {this->Name = name; }
    // void move(){}

};

class Seeing 
 {
    public:
    // void GetRobotName() { cout << "Geekname is:" << Name; }
    // void SetRobotName(string name) {Name = name; }
    // void look(){}
};

class Shooting 
 {
    // public:
    // void GetRobotName() { cout << "Geekname is:" << Name; }
    // void SetRobotName(string name) {Name = name; }
    // void Shoot(){}
};

class Steping 
 {
    // public:
    // void GetRobotName() { cout << "Geekname is:" << Name; }
    // void SetRobotName(string name) {Name = name; }
    // void Stomp(){}
};

class RoboCop: public Shooting , public Seeing , public Moving{
    public:
    RoboCop(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
    }

};

class Terminator: public Seeing , public Moving , public Steping{
    public:
    Terminator(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
    }

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


int start(Node* head, int steps,  Robot robotlist[3]){
    for(int i = 0; i< 3; i++){
        cout << robotlist[i].cordinate.x << robotlist[i].cordinate.y << endl;
        setLinkedList(head, robotlist[i].cordinate.x, robotlist[i].cordinate.y);
    }
    for(int i = 0; i< steps; i++){
        cout << "step "<< i+1 <<endl;
    }

 return 1;
}

int main(){
    Node* head = NULL;
    int steps = 10;
    struct Cordinate s;
  	s.x = 2;
	s.y = 2;

    struct Cordinate s2;
  	s2.x = 5;
	s2.y = 5;

    struct Cordinate s3;
  	s3.x = 7;
	s3.y = 7;

    buildList(&head, 9,9);
    // queue<int> gquiz;
    // gquiz.push(10);
    // gquiz.push(20);
    // gquiz.push(30);
    // cout << sizeList(head)<<endl;
    // printBoard(head, 3,3);
    // searchLinkedList(head, 1,1);
    RoboCop r1("sharaf", s );
    RoboCop r2("zan-e sharaf", s2 );
    Terminator r3("bach-e sharaf", s3 );
    Robot rlist[3];
    rlist[0]= r1;
    rlist[1]= r2;
    rlist[2]= r3;
    start(head, steps, rlist);
    // setLinkedList(head, 2,2);
    printBoard(head);
    // move(head, s);

    // move(1, 2);    
    //  Moving newRobot1;

    // cout << newRobot1.RobotType+ " check type first time \n";
    // newRobot1.SetRobotType("Type 1");
    // cout << newRobot1.RobotType+ " check type second time \n";

    // cout << newRobot1.Name+ " check name first time \n";
    // newRobot1.SetRobotName("Behnaz");
    // cout << newRobot1.Name+ " check name second time \n";



    return 0;
}