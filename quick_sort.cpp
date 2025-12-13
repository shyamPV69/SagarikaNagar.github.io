#include <iostream>
#include <string>
using namespace std;

void swapPair(float& a, float& b, string& ca, string& cb) {
    float td = a; a = b; b = td;
    string tc = ca; ca = cb; cb = tc;
}

int partition(float distances[], string cities[], int low, int high) {
    float pivot = distances[high];
    string pivotCity = cities[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (distances[j] <= pivot) {
            i++;
            swapPair(distances[i], distances[j], cities[i], cities[j]);
        }
    }
    swapPair(distances[i + 1], distances[high], cities[i + 1], cities[high]);
    return i + 1;
}

void quickSort(float distances[], string cities[], int low, int high) {
    if (low < high) {
        int pi = partition(distances, cities, low, high);
        quickSort(distances, cities, low, pi - 1);
        quickSort(distances, cities, pi + 1, high);
    }
}

int main() {
    string cities[] = {"Mangalore", "Kundapura", "Karkala", "Udupi", "Bantwal"};
    float distances[] = {52.47f, 31.87f, 34.1f, 28.5f, 45.2f};
    int n = 5;
    quickSort(distances, cities, 0, n - 1);
    cout << "Quick sorted cities by distance:\n";
    for (int i = 0; i < n; i++) {
        cout << cities[i] << ": " << distances[i] << " km\n";
    }
    return 0;
}
