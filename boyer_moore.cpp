#include <iostream>
#include <string>
using namespace std;

void badCharHeuristic(const string& pat, int bad[]) {
    for (int i = 0; i < 256; i++) bad[i] = -1;
    for (int i = 0; i < (int)pat.size(); i++) bad[(unsigned char)pat[i]] = i;
}

void boyerMooreSearch(const string& txt, const string& pat) {
    int n = (int)txt.size();
    int m = (int)pat.size();
    if (m == 0 || m > n) {
        cout << "Pattern not found\n";
        return;
    }
    int bad[256];
    badCharHeuristic(pat, bad);
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j]) j--;
        if (j < 0) {
            cout << "Pattern found at position " << s << "\n";
            s += (s + m < n) ? m - bad[(unsigned char)txt[s + m]] : 1;
        } else {
            s += max(1, j - bad[(unsigned char)txt[s + j]]);
        }
    }
}

int main() {
    string text = "IT Park and Education Hub near Mangroves";
    string pattern1 = "Park";
    string pattern2 = "Hub";
    boyerMooreSearch(text, pattern1);
    boyerMooreSearch(text, pattern2);
    return 0;
}
