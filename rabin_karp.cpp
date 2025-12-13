#include <iostream>
#include <string>
using namespace std;

void rabinKarpSearch(const string& text, const string& pattern) {
    const long long mod = 1000000007LL;
    const long long base = 257LL;
    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m == 0 || m > n) {
        cout << "Pattern not found\n";
        return;
    }
    long long pHash = 0, tHash = 0, power = 1;
    for (int i = 0; i < m; i++) {
        pHash = (pHash * base + pattern[i]) % mod;
        tHash = (tHash * base + text[i]) % mod;
        if (i < m - 1) power = (power * base) % mod;
    }
    for (int i = 0; i <= n - m; i++) {
        if (pHash == tHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) { match = false; break; }
            }
            if (match) {
                cout << "Pattern found at position " << i << "\n";
            }
        }
        if (i < n - m) {
            tHash = (tHash - text[i] * power) % mod;
            if (tHash < 0) tHash += mod;
            tHash = (tHash * base + text[i + m]) % mod;
        }
    }
}

int main() {
    string location = "Commercial City Center";
    string search1 = "City";
    string search2 = "Center";
    rabinKarpSearch(location, search1);
    rabinKarpSearch(location, search2);
    return 0;
}
