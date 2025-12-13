#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Color { RED, BLACK };

struct RBNode {
    string key;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    RBNode(const string& k)
        : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
public:
    RedBlackTree() : root(nullptr) {}
    
    void insert(const string& key) {
        RBNode* z = new RBNode(key);
        RBNode* y = nullptr;
        RBNode* x = root;
        while (x) {
            y = x;
            if (z->key < x->key) x = x->left;
            else x = x->right;
        }
        z->parent = y;
        if (!y) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
        root->color = BLACK;
    }
    
    void display() const {
        cout << "Red-Black Tree (preorder):\n";
        preorder(root);
    }
    
private:
    RBNode* root;
    
    void preorder(RBNode* n) const {
        if (!n) return;
        cout << n->key << " [" << (n->color == RED ? "R" : "B") << "]\n";
        preorder(n->left);
        preorder(n->right);
    }
};

int main() {
    RedBlackTree rbt;
    rbt.insert("Sagarika Nagar");
    rbt.insert("Kundapura");
    rbt.insert("Mangalore");
    rbt.display();
    return 0;
}
