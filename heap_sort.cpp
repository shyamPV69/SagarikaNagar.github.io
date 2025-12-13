#include <iostream>
#include <string>
using namespace std;

void swapPair(float& a, float& b, string& ca, string& cb) {
    float td = a; a = b; b = td;
    string tc = ca; ca = cb; cb = tc;
}

void heapify(float distances[], string cities[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && distances[l] > distances[largest]) largest = l;
    if (r < n && distances[r] > distances[largest]) largest = r;
    if (largest != i) {
        swapPair(distances[i], distances[largest], cities[i], cities[largest]);
        heapify(distances, cities, n, largest);
    }
}

void heapSort(float distances[], string cities[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(distances, cities, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swapPair(distances[0], distances[i], cities[0], cities[i]);
        heapify(distances, cities, i, 0);
    }
}

int main() {
    string cities[] = {"Mangalore", "Kundapura", "Karkala", "Udupi", "Bantwal", "Putur"};
    float distances[] = {52.47f, 31.87f, 34.1f, 28.5f, 45.2f, 38.7f};
    int n = 6;
    heapSort(distances, cities, n);
    cout << "Heap sorted cities (farthest to closest):\n";
    for (int i = 0; i < n; i++) {
        cout << cities[i] << ": " << distances[i] << " km\n";
    }
    return 0;
}
