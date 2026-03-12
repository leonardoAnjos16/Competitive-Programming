#include <bits/stdc++.h>

using namespace std;

int to_value(string card) {
    if (card == "A") return 1;
    if (card == "10") return 10;
    if (card == "J") return 11;
    if (card == "Q") return 12;
    if (card == "K") return 13;
    return card[0] - '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, string>> cards;

    string card;
    bool is_card = true;

    while (cin >> card) {
        if (is_card) cards.emplace_back(to_value(card), card);
        is_card = !is_card;
    }

    int n = cards.size();
    multiset<pair<int, string>> sorted;

    for (int i = 0; i < n; i++) {
        sorted.insert(cards[i]);
        if (!i) continue;

        cout << "[";

        bool first = true;
        for (auto [_, card]: sorted) {
            if (!first) cout << ",";

            cout << card;
            first = false;
        }

        for (int j = i + 1; j < n; j++)
            cout << "," << cards[j].second;

        cout << "]\n";
    }
}