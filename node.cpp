#include <iostream>
#include <queue>

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



int start(Node** head, int steps,  Cordinate startCordinate){
    cout << startCordinate.x << startCordinate.y << endl;

 return 1;
}

int main(){
    Node* head = NULL;
    int steps = 20;
    struct Cordinate s;
  	s.x = 2;
	s.y = 2;

    buildList(&head, 3,3);
    // queue<int> gquiz;
    // gquiz.push(10);
    // gquiz.push(20);
    // gquiz.push(30);
    // cout << sizeList(head)<<endl;
    // printBoard(head, 3,3);
    // searchLinkedList(head, 1,1);
    // start(&head, steps, s);
    setLinkedList(head, 2,2);
    printBoard(head); cout << endl;
    setLinkedList(head, 3,3);
    printBoard(head);


    return 0;
}