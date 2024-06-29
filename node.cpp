#include <iostream>
#include <cstdlib> 

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

bool searchLinkedList(Node* head, int x, int y) {
    // Traverse the Linked List
    while (head != nullptr) {
        // Check if the current node's data matches the target value
        if (head->cordinate.x == x && head->cordinate.y == y) {

            cout<< "("<< head->cordinate.x<<","<<head->cordinate.y<<") :"<<  "occuoied: "<<  ",  ooccupied by: " << head->occupyBy << endl;
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

bool setLinkedList(Node* head, Cordinate cordinate, string robotType) {
    // Traverse the Linked List
    while (head != nullptr) {
        // Check if the current node's data matches the target value
        if (head->cordinate.x == cordinate.x && head->cordinate.y == cordinate.y) {
            head->occupied = true;
            head->occupyBy = robotType;
            return true;  // Value found
        }
        // Move to the next node
        head = head->next;
    }
    
    return false;  // Value not found
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
        head = head->next;
    }

};

class Robot {
    public:
    string Name;
    Cordinate cordinate;
    string RobotType;
    int life;
    int headcount;
    void GetRobotType() { cout << "Geekname is:" << RobotType; }
    void SetRobotType(string robotType) {RobotType = robotType; }

};

class Moving 
 {
    public:
    bool moveUpLeft(Node* head);
    bool moveUp(Node* head);
    bool moveUpRight(Node* head);
    bool moveLeft(Node* head);
    bool moveRight(Node* head);
    bool moveDownLeft(Node* head);
    bool moveDown(Node* head);
    bool moveDownRight(Node* head);

};

class Seeing
 {
    public:
    bool lookUpLeft(Node* head);
    bool lookUp(Node* head);
    bool lookUpRight(Node* head);
    bool lookLeft(Node* head);
    bool lookRight(Node* head);
    bool lookDownLeft(Node* head);
    bool lookDown(Node* head);
    bool lookDownRight(Node* head);
};

class Shooting
 {
    public:
    bool Shoot();
};

class Steping 
 {
    // public:
    // void GetRobotName() { cout << "Geekname is:" << Name; }
    // void SetRobotName(string name) {Name = name; }
    // void Stomp(){}
};

class RoboCop:public Robot, Seeing, Moving, Shooting{
    public:
    RoboCop(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
      this->life = 3;
      this->headcount = 0;
      this->RobotType = __func__;
    }
    bool lookUpLeft(Node* head){
        return searchLinkedList(head,  this->cordinate.x - 1, this->cordinate.y + 1);
    }
    bool lookUp(Node* head){
        return searchLinkedList(head,  this->cordinate.x , this->cordinate.y + 1);
    }
    bool lookUpRight(Node* head){
        return searchLinkedList(head,  this->cordinate.x + 1 , this->cordinate.y + 1);
    }
    bool lookLeft(Node* head){
        return searchLinkedList(head,  this->cordinate.x - 1 , this->cordinate.y);
    }
    bool lookRight(Node* head){
        return searchLinkedList(head,  this->cordinate.x + 1 , this->cordinate.y);
    }
    bool lookDownLeft(Node* head){
        return searchLinkedList(head,  this->cordinate.x - 1 , this->cordinate.y - 1);
    }
    bool lookDown(Node* head){
        return searchLinkedList(head,  this->cordinate.x  , this->cordinate.y - 1);
    }
    bool lookDownRight(Node* head){
        return searchLinkedList(head,  this->cordinate.x + 1 , this->cordinate.y - 1);
    }

    bool moveUpLeft(Node* head){
        if(this->lookUpLeft(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x - 1;
            this->cordinate.y  = this->cordinate.y + 1;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to Up Left" << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to Up Left" << endl;
            return false;
        }
    };
    bool moveUp(Node* head){
        if(this->lookUp(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x ;
            this->cordinate.y  = this->cordinate.y + 1;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to Up " << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to Up" << endl;
            return false;
        }

    };
    bool moveUpRight(Node* head){
                if(this->lookUpRight(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x + 1;
            this->cordinate.y  = this->cordinate.y + 1;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to Up Right" << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to Up Right" << endl;
            return false;
        }

    };
    bool moveLeft(Node* head){
                if(this->lookLeft(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x - 1;
            this->cordinate.y  = this->cordinate.y ;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to Left" << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to Left" << endl;
            return false;
        }

    };
    bool moveRight(Node* head){

        if(this->lookRight(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x + 1;
            this->cordinate.y  = this->cordinate.y ;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to Right" << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to Right" << endl;
            return false;
        }
    };
    bool moveDownLeft(Node* head){
        if(this->lookDownLeft(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x - 1;
            this->cordinate.y  = this->cordinate.y - 1;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to DownLeft" << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to DownLeft" << endl;
            return false;
        }

    };
    bool moveDown(Node* head){

        if(this->lookDown(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x ;
            this->cordinate.y  = this->cordinate.y - 1;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to Down" << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to Down" << endl;
            return false;
        }
    };
    bool moveDownRight(Node* head){
        if(this->lookDownRight(head) == true){
            resetLinkedList(head, this->cordinate.x, this->cordinate.y);
            this->cordinate.x  = this->cordinate.x + 1;
            this->cordinate.y  = this->cordinate.y - 1;
            setLinkedList(head, this->cordinate, this->Name);
            cout << "Moved to DownRight" << endl;
            printBoard(head);
            return true;
        }else{
            cout << "Can not move to DownRight" << endl;
            return false;
        }

    };

    bool fire(Node* head){
        while (head != nullptr) {
            // Check if the current node's data matches the target value
            if (head->cordinate.x == cordinate.x && head->cordinate.y == cordinate.y  &&   head->occupied == true) {
                resetLinkedList(head, cordinate.x, cordinate.y);
                cout << "Target successfully destroied."<< endl;
                return true;  // Value found
            }
            // Move to the next node
            head = head->next;
        }
        cout << "Target Does not exist."<< endl;
        return false; 
    }

};

class Terminator:public Robot{
    public:
    Terminator(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
      this->life = 3;
      this->headcount = 0;
      this->RobotType = __func__;
    }

};

class TerminatorRobocop:public Robot{
    public:
    TerminatorRobocop(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
      this->life = 3;
      this->headcount = 0;
      this->RobotType = __func__;
    }

};

class BlueThunder: public Robot{
    public:
    BlueThunder(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
      this->life = 3;
      this->headcount = 0;
      this->RobotType = __func__;
    }

};

class MadBot: public Robot{
    public:
    MadBot(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
      this->life = 3;
      this->headcount = 0;
      this->RobotType = __func__;
    }

};

class RoboTank: public Robot{
    public:
    RoboTank(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
      this->life = 3;
      this->headcount = 0;
      this->RobotType = __func__;
    }

};

class UltimateRobot: Robot{
    public:
    UltimateRobot(string name, Cordinate cordinate) {     // Constructor
      this->Name      = name;
      this->cordinate = cordinate;
      this->life = 3;
      this->headcount = 0;
      this->RobotType = __func__;
    }

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


bool fire(Node* head, Cordinate cordinate){
        // Traverse the Linked List
    while (head != nullptr) {
        // Check if the current node's data matches the target value
        if (head->cordinate.x == cordinate.x && head->cordinate.y == cordinate.y  &&   head->occupied == true) {
            resetLinkedList(head, cordinate.x, cordinate.y);
            cout << "Target successfully destroied."<< endl;
            return true;  // Value found
        }
        // Move to the next node
        head = head->next;
    }
    cout << "Target Does not exist."<< endl;
    return false; 

}

int start(Node* head, int steps,  Robot robotlist[3]){
    for(int i = 0; i< 3; i++){
        setLinkedList(head, robotlist[i].cordinate, robotlist[i].Name);
    }
    // for(int i = 0; i< steps; i++){
    //     cout << "step "<< i+1 <<endl;
    // }

 return 1;
}

Cordinate getRandomCoordinate(Cordinate c1,  Cordinate c2) {
    Cordinate cord;
    cord.x = c1.x + rand() % (c2.x - c1.x + 1);  // Generate a random x within the range
    cord.y = c1.y + rand() % (c2.y - c1.y + 1);  // Generate a random y within the range
    return cord;
}


int main(){
    srand(time(0)); // initiate the randomizer
    Node* head = NULL;
    int steps = 10;
    struct Cordinate s;
  	s.x = 2;
	s.y = 2;

    struct Cordinate s2;
  	s2.x = 3;
	s2.y = 2;

    struct Cordinate s3;
  	s3.x = 7;
	s3.y = 7;

    RoboCop r1("sharaf", s );
    RoboCop r2("zan-e sharaf", s2 );
    Terminator r3("bach-e sharaf", s3 );
    Robot rlist[3];
    rlist[0]= r1;
    rlist[1]= r2;
    rlist[2]= r3;

    buildList(&head, 9,9);
    start(head, steps, rlist);
    printBoard(head);
    // printBoard(head);
    // Cordinate c = getRandomCoordinate(s, s3);
    // cout << printf("(x, y) : (%d, %d)", c.x, c.y) << endl;
    r1.lookDown(head);
    r1.lookDownLeft(head);
    r1.lookDownRight(head);
    r1.lookLeft(head);
    r1.lookRight(head);
    r1.lookUp(head);
    r1.lookUpRight(head);
    r1.lookUpLeft(head);
    fire(head, s2);
    
    // printBoard(head);
    // r1.moveUpRight(head);
    // r1.moveUp(head);
    // r1.moveDown(head);
    // r1.moveDownLeft(head);
    // r1.moveDownRight(head);
    // r1.moveLeft(head);
    // r1.moveRight(head);
    // r1.moveUpLeft(head);



    return 0;
}