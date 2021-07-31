#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<tuple<int, int, int, int>> siths(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        siths[i] = make_tuple(a, b, c, i + 1);
    }

    set<int> losers;
    for (int i = 0; i < n; i++)
        losers.insert(i + 1);

    for (int i = 0; i < 2; i++) {
        sort(siths.begin(), siths.end());

        pair<int, int> mns = make_pair(INT_MAX, INT_MAX);
        for (int j = 0; j < n; j++) {
            int a, b, c, idx;
            tie(a, b, c, idx) = siths[j];

            if ((b > mns.first || c > mns.second) && losers.count(idx))
                losers.erase(idx);

            mns.first = min(mns.first, b);
            mns.second = min(mns.second, c);
        }

        for (int j = 0; j < n; j++) {
            int a, b, c, idx;
            tie(a, b, c, idx) = siths[j];
            siths[j] = make_tuple(b, a, c, idx);
        }
    }

    int ans = losers.size();
    cout << ans << "\n";

    for (auto it = losers.begin(); it != losers.end(); it++) {
        if (it != losers.begin()) cout << " ";
        cout << *it;
    }

    cout << "\n";
}