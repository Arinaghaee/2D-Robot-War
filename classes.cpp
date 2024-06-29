


class Node{
    public:
    int data;
    string occupyBy;
    bool occupied;
    Cordinate cordinate;
    Node *next;
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


