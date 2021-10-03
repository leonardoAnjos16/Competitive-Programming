#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second >= a.first && b.second < b.first) return true;
    if (a.second < a.first && b.second >= b.first) return false;

    if (a.second >= a.first)
        return a.first < b.first;

    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<pair<int, int>> drives(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            drives[i] = make_pair(a, b);
        }

        sort(drives.begin(), drives.end(), comp);

        long ans = 0LL, free = 0LL;
        for (int i = 0; i < n; i++) {
            if (free < drives[i].first) {
                long aux = drives[i].first - free;
                ans += aux; free += aux;
            }

            free -= drives[i].first;
            free += drives[i].second;
        }

        cout << ans << "\n";
    }
}