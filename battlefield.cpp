#include <iostream>
using namespace std ;

struct Node {
    int x;
    int y;
    Node* next;
    
    Node(int x_coord, int y_coord) : x(x_coord), y(y_coord), next(nullptr) {}
};

class Battlefield {
private:
    Node* head;
    int rows;
    int cols;
    
public:
    Battlefield(int rows, int cols) : head(nullptr), rows(rows), cols(cols) {
        createBattlefield();
    }

    ~Battlefield() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void createBattlefield() {
        Node* tail = nullptr;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                Node* newNode = new Node(i, j);
                if (!head) {
                    head = newNode;
                } else {
                    tail->next = newNode;
                }
                tail = newNode;
            }
        }
    }

    void printBattlefield() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "(" << current->x << ", " << current->y << ")";
            if (current->next) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Battlefield battlefield(rows, cols);
    battlefield.printBattlefield();

    return 0;
}
