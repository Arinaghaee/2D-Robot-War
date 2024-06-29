



struct Cordinate { int x; int y;};

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

void push(Node* * head_ref, int new_data, struct Cordinate cordinate){
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data;
    new_node->cordinate = cordinate;
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
};

int sizeList(Node* head){
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
