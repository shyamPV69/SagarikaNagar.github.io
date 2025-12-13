#include <iostream>
#include <string>
using namespace std;

void insertionSort(float distances[], string cities[], int n) {
    for (int i = 1; i < n; i++) {
        float keyDist = distances[i];
        string keyCity = cities[i];
        int j = i - 1;
        while (j >= 0 && distances[j] > keyDist) {
            distances[j + 1] = distances[j];
            cities[j + 1] = cities[j];
            j--;
        }
        distances[j + 1] = keyDist;
        cities[j + 1] = keyCity;
    }
}

int main() {
    string cities[] = {"Mangalore", "Karkala", "Kundapura"};
    float distances[] = {52.47f, 34.1f, 31.87f};
    int n = 3;
    insertionSort(distances, cities, n);
    cout << "Insertion sort result:\n";
    for (int i = 0; i < n; i++) {
        cout << cities[i] << ": " << distances[i] << " km\n";
    }
    return 0;
}
