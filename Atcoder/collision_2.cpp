#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        points[i] = make_pair(X, Y);
    }

    string S; cin >> S;

    map<int, vector<pair<int, char>>> rows;
    for (int i = 0; i < N; i++) {
        auto [X, Y] = points[i];
        rows[Y].emplace_back(X, S[i]);
    }

    bool collision = false;
    for (auto [Y, row]: rows) {
        sort(row.begin(), row.end());

        int R = -1, L = -1;
        for (int i = 0; i < (int) row.size(); i++) {
            if (R == -1 && row[i].second == 'R') R = i;
            else if (row[i].second == 'L') L = i;
        }

        if (R != -1 && L != -1 && R < L) {
            collision = true;
            break;
        }
    }

    cout << (collision ? "Yes" : "No") << "\n";
}