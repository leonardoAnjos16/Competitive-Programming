#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first - a.second > b.first - b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<pair<int, int>> dragons(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dragons[i] = make_pair(a, b);
    }

    sort(dragons.begin(), dragons.end(), cmp);

    long ans = 0LL, rem = 0LL;
    for (int i = 0; i < n; i++) {
        long extra = max(dragons[i].first - rem, 0LL);
        ans += extra; rem += extra - dragons[i].second;
    }

    cout << ans << "\n";
}