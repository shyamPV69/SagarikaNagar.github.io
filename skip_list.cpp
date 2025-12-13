#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct SkipNode {
    string city;
    float distance;
    vector<SkipNode*> forward;
    SkipNode(int level, const string& c, float d) : city(c), distance(d), forward(level + 1, nullptr) {}
};

class SkipList {
public:
    SkipList(int maxLevel_, float p_) : maxLevel(maxLevel_), p(p_), level(0) {
        header = new SkipNode(maxLevel, "", -1.0f);
        srand((unsigned)time(0));
    }
    void insert(const string& city, float distance) {
        vector<SkipNode*> update(maxLevel + 1);
        SkipNode* x = header;
        for (int i = level; i >= 0; i--) {
            while (x->forward[i] && x->forward[i]->distance < distance) x = x->forward[i];
            update[i] = x;
        }
        int lv = randomLevel();
        if (lv > level) {
            for (int i = level + 1; i <= lv; i++) update[i] = header;
            level = lv;
        }
        SkipNode* n = new SkipNode(lv, city, distance);
        for (int i = 0; i <= lv; i++) {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
    void display() const {
        cout << "Skip List (by distance):\n";
        SkipNode* x = header->forward[0];
        while (x) {
            cout << x->city << " (" << x->distance << " km)\n";
            x = x->forward[0];
        }
    }
private:
    int maxLevel;
    float p;
    int level;
    SkipNode* header;
    int randomLevel() {
        int lv = 0;
        while (((float)rand() / RAND_MAX) < p && lv < maxLevel) lv++;
        return lv;
    }
};

int main() {
    SkipList skipList(3, 0.5f);
    skipList.insert("Kundapura", 31.87f);
    skipList.insert("Mangalore", 52.47f);
    skipList.insert("Karkala", 34.1f);
    skipList.display();
    return 0;
}
