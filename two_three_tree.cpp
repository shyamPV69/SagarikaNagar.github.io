#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TwoThreeNode {
    bool isLeaf;
    vector<string> keys;
    vector<TwoThreeNode*> children;
    TwoThreeNode(bool leaf) : isLeaf(leaf) {}
};

void traverse23(TwoThreeNode* node) {
    if (!node) return;
    if (node->isLeaf) {
        for (const auto& k : node->keys) cout << k << " ";
        return;
    }
    if (node->children.size() == 2 && node->keys.size() == 1) {
        traverse23(node->children[0]);
        cout << node->keys[0] << " ";
        traverse23(node->children[1]);
    } else if (node->children.size() == 3 && node->keys.size() == 2) {
        traverse23(node->children[0]);
        cout << node->keys[0] << " ";
        traverse23(node->children[1]);
        cout << node->keys[1] << " ";
        traverse23(node->children[2]);
    } else {
        for (const auto& k : node->keys) cout << k << " ";
        for (auto* ch : node->children) traverse23(ch);
    }
}

int main() {
    TwoThreeNode* root = new TwoThreeNode(false);
    root->keys = {"Karkala", "Mangalore"};
    
    TwoThreeNode* child1 = new TwoThreeNode(true);
    child1->keys = {"Kundapura"};
    
    TwoThreeNode* child2 = new TwoThreeNode(true);
    child2->keys = {"Sagarika Nagar"};
    
    root->children = {child1, child2};
    
    cout << "2-3 Tree traversal: ";
    traverse23(root);
    cout << endl;
    return 0;
}
