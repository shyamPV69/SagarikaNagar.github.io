#include <bits/stdc++.h>
using namespace std;

vector<int> build_lps(const string &pat) {
    int m = pat.size();
    vector<int> lps(m);
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) len = lps[len - 1];
            else { lps[i] = 0; i++; }
        }
    }
    return lps;
}

vector<int> kmp_search(const string &txt, const string &pat) {
    vector<int> res;
    if (pat.empty()) return res;
    vector<int> lps = build_lps(pat);
    int i = 0, j = 0;
    int n = txt.size(), m = pat.size();
    while (i < n) {
        if (txt[i] == pat[j]) { i++; j++; }
        if (j == m) { res.push_back(i - j); j = lps[j - 1]; }
        else if (i < n && txt[i] != pat[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return res;
}

int main() {
    string text = "abxabcabcaby";
    string pat  = "abcaby";
    auto occ = kmp_search(text, pat);
    if (occ.empty()) cout << "No occurrence\n";
    else {
        cout << "Pattern found at indices: ";
        for (int i : occ) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
