#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> shows(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        shows[i] = make_pair(l, r);
    }

    sort(shows.begin(), shows.end());

    bool possible = true;
    int first = -1, second = -1;

    for (int i = 0; i < n && possible; i++) {
        if (shows[i].first > first) first = shows[i].second;
        else if (shows[i].first > second) second = shows[i].second;
        else possible = false;
    }

    cout << (possible ? "YES" : "NO") << "\n";
}