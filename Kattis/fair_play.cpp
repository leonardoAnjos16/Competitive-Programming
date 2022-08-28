#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        int b, p;
        cin >> b >> p;
        pairs[i] = make_pair(b, p);
    }

    sort(pairs.begin(), pairs.end());

    if (n & 1) cout << "impossible\n";
    else {
        int b = pairs[0].first + pairs[n - 1].first;
        int p = pairs[0].second + pairs[n - 1].second;

        bool possible = true;
        for (int i = 1, j = n - 2; i < j && possible; i++, j--)
            if ((pairs[i].first + pairs[j].first) != b || (pairs[i].second + pairs[j].second) != p)
                possible = false;

        cout << (possible ? "possible" : "impossible") << "\n";
    }
}