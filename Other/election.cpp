#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    map<string, string> party;
    for (int i = 0; i < n; i++) {
        string candidate;
        getline(cin, candidate);
        getline(cin, party[candidate]);
    }

    int m;
    cin >> m;
    cin.ignore();

    map<string, int> votes;
    for (int i = 0; i < m; i++) {
        string candidate;
        getline(cin, candidate);

        if (!party.count(candidate)) continue;
        votes[candidate]++;
    }

    string winner = "";
    int winners = 0, mx_votes = 0;

    for (auto [candidate, cnt]: votes) {
        if (cnt == mx_votes) winners++;
        else if (cnt > mx_votes) {
            winners = 1;
            mx_votes = cnt;
            winner = party[candidate];
        }
    }

    if (winners != 1) cout << "tie\n";
    else cout << winner << "\n";
}