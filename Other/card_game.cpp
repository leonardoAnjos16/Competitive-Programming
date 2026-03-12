#include <bits/stdc++.h>

using namespace std;

int get_index(char c, string &order) {
    for (int i = 0; i < (int) order.size(); i++)
        if (order[i] == c) return i;

    return order.size();
}

int lis(vector<pair<char, int>> &values, string &order) {
    vector<pair<char, int>> aux;
    for (auto value: values) {
        auto it = upper_bound(aux.begin(), aux.end(), value, [&](pair<char, int> const &a, pair<char, int> const &b) {
            int ia = get_index(a.first, order), ib = get_index(b.first, order);
            return ia < ib || (ia == ib && a.second < b.second);
        });

        if (it == aux.end()) aux.push_back(value);
        else *it = value;
    }

    return aux.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<pair<char, int>> cards(N);
    for (int i = 0; i < N; i++) {
        string card; cin >> card;
        cards[i] = make_pair(card[0], stoi(card.substr(1)));
    }

    int ans = INT_MAX;
    string suits = "ERSW";

    do ans = min(ans, N - lis(cards, suits));
    while (next_permutation(suits.begin(), suits.end()));

    cout << ans << "\n";
}