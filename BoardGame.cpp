using namespace std;
#include<iostream>

int getCount(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void printBoard(int row, int column){
    for(int i=0; i<row ;i++){
        for(int j=0; j<column ; j++){
            cout<< "o ";
        }
        cout<<endl;
    }
}

int main(){
printBoard(5,5);

    

    return 0;
}