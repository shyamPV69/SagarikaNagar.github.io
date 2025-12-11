#include <bits/stdc++.h>
using namespace std;

int main() {
    // card_number -> balance
    unordered_map<string, int> cardBalance;

    // add some sample cards
    cardBalance["SGR001"] = 120;
    cardBalance["SGR002"] = 0;
    cardBalance["SGR003"] = 45;

    string card;
    cout << "Enter card number: ";
    cin >> card;

    if (cardBalance.find(card) == cardBalance.end()) {
        cout << "Card not found / invalid.\n";
    } else {
        int bal = cardBalance[card];
        cout << "Card found. Balance = " << bal << "\n";
        if (bal > 0) cout << "Access allowed.\n";
        else cout << "Low balance. Please recharge.\n";
    }

    return 0;
}
