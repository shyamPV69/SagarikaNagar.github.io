#include <iostream>
#include <string>
using namespace std;

void bruteForceSearch(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) {
            cout << "Pattern found at position " << i << "\n";
            return;
        }
    }
    cout << "Pattern not found\n";
}

int main() {
    string cityName = "Sagarika Nagar";
    string pattern1 = "Nagar";
    string pattern2 = "City";
    bruteForceSearch(cityName, pattern1);
    bruteForceSearch(cityName, pattern2);
    return 0;
}
