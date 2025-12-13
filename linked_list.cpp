#include <iostream>
using namespace std ;

struct Node {
    string location;
    Node* next;
    Node(const string& loc) : location(loc), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { clear(); }
    
    void addLocation(const string& loc) {
        Node* n = new Node(loc);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    
    void displayPath() const {
        Node* cur = head;
        while (cur) {
            cout << cur->location << "\n";
            cur = cur->next;
        }
    }
    
private:
    Node* head;
    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = nullptr;
    }
};

int main() {
    LinkedList path;
    path.addLocation("Sagarika Nagar" );
    path.addLocation("Kundapura" );
    path.addLocation("Mangalore" );
    path.displayPath();
    return 0 ;
}
