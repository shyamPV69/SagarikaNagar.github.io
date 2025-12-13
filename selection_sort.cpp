#include <iostream>
#include <string>
using namespace std;

void selectionSort(float distances[], string cities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (distances[j] < distances[minIdx]) minIdx = j;
        }
        if (minIdx != i) {
            float td = distances[i];
            distances[i] = distances[minIdx];
            distances[minIdx] = td;
            string tc = cities[i];
            cities[i] = cities[minIdx];
            cities[minIdx] = tc;
        }
    }
}

int main() {
    string cities[] = {"Kundapura", "Mangalore", "Karkala", "Udupi"};
    float distances[] = {31.87f, 52.47f, 34.1f, 28.5f};
    int n = 4;
    selectionSort(distances, cities, n);
    cout << "Cities sorted by distance:\n";
    for (int i = 0; i < n; i++) {
        cout << cities[i] << ": " << distances[i] << " km\n";
    }
    return 0;
}
