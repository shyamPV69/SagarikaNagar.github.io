#include <iostream>
#include <string>
using namespace std;

void bubbleSort(float distances[], string cities[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (distances[j] > distances[j + 1]) {
                float td = distances[j];
                distances[j] = distances[j + 1];
                distances[j + 1] = td;
                string tc = cities[j];
                cities[j] = cities[j + 1];
                cities[j + 1] = tc;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    string cities[] = {"Kundapura", "Mangalore", "Karkala"};
    float distances[] = {31.87f, 52.47f, 34.1f};
    int n = 3;
    bubbleSort(distances, cities, n);
    cout << "Sorted by distance:\n";
    for (int i = 0; i < n; i++) {
        cout << cities[i] << " (" << distances[i] << " km)\n";
    }
    return 0;
}
