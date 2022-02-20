#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    set<pair<int, int>> remaining;
    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        remaining.emplace(a[i], i);
        left[i] = i - 1;
        right[i] = i + 1;
    }

    int turn = 0;
    vector<int> ans(n);

    while (!remaining.empty()) {
        auto last = remaining.end();
        int idx = (--last)->second;
        remaining.erase(last);
        ans[idx] = turn + 1;

        int l = left[idx];
        for (int i = 0; i < k && l >= 0; i++) {
            remaining.erase(make_pair(a[l], l));
            ans[l] = turn + 1;
            l = left[l];
        }

        int r = right[idx];
        for (int i = 0; i < k && r < n; i++) {
            remaining.erase(make_pair(a[r], r));
            ans[r] = turn + 1;
            r = right[r];
        }

        if (l >= 0) right[l] = r;
        if (r < n) left[r] = l;
        turn = 1 - turn;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i];

    cout << "\n";
}