#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int distance(string &s, string &t, int i = 0, int j = 0) {
    if (i >= (int) s.size()) return (int) t.size() - j;
    if (j >= (int) t.size()) return (int) s.size() - i;

    int &ans = memo[i][j];
    if (~ans) return ans;

    ans = min(distance(s, t, i + 1, j), distance(s, t, i, j + 1)) + 1;
    ans = min(ans, distance(s, t, i + 1, j + 1) + (s[i] != t[j]));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int points[5] = {0};
    while (N--) {
        string s; cin >> s;

        int dists[5] = {0};
        for (int i = 0; i < 5; i++) {
            string t; cin >> t;

            memo.assign((int) s.size() + 5, vector<int>((int) t.size() + 5, -1));
            dists[i] = distance(s, t);
        }

        int mn = INT_MAX;
        for (int i = 0; i < 5; i++)
            mn = min(mn, dists[i]);

        for (int i = 0; i < 5; i++)
            if (dists[i] == mn)
                points[i] += !dists[i] ? 2 : 1;
    }

    int mx = 0;
    for (int i = 0; i < 5; i++)
        mx = max(mx, points[i]);

    cout << (mx / 2);
    if (mx & 1) cout << ".5";
    else cout << ".0";
    cout << "\n";

    bool space = false;
    for (int i = 0; i < 5; i++)
        if (points[i] == mx) {
            if (space) cout << " ";
            cout << (i + 1);
            space = true;
        }

    cout << "\n";
}