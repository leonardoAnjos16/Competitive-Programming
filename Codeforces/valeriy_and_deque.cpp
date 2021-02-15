#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_Q = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; cin >> n >> q;

    deque<int> a;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        int ai; cin >> ai;
        mx = max(mx, ai);
        a.push_back(ai);
    }

    int cnt = 0;
    pair<int, int> ans[MAX_N];

    while (a.front() < mx) {
        int A = a.front(); a.pop_front();
        int B = a.front(); a.pop_front();

        ans[++cnt] = { A, B };

        if (A > B) a.push_front(A), a.push_back(B);
        else a.push_front(B), a.push_back(A);
    }

    cnt++;
    while (q--) {
        long long int m; cin >> m;

        if (m < cnt)
            cout << ans[m].first << " " << ans[m].second << "\n";
        else {
            m = (m - cnt) % (n - 1);
            cout << a.front() << " " << *(a.begin() + m + 1) << "\n";
        }
    }
}