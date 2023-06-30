#include <bits/stdc++.h>

using namespace std;

#define llong long long int

llong solve(int N, vector<int> &x, vector<int> &y, int idx, vector<int> &path) {
    if (idx < 0 || idx >= N) return LLONG_MAX;

    llong ans = 0LL;
    int l = idx, r = idx;
    path.push_back(idx + 1);

    while (l > 0 || r < N - 1) {
        if (!l) {
            ans += y[idx];
            idx = ++r;
        } else if (r + 1 >= N) {
            ans += x[idx];
            idx = --l;
        } else if (x[idx] < y[idx]) {
            ans += x[idx];
            idx = --l;
        } else {
            ans += y[idx];
            idx = ++r;
        }

        path.push_back(idx + 1);
    }

    ans += min(x[idx], y[idx]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++)
        cin >> x[i] >> y[i];

    int left = 0;
    for (int i = 0; i < N; i++)
        if (x[i] < y[i])
            left++;

    vector<int> path;
    llong ans = solve(N, x, y, left, path);

    vector<int> npath;
    llong nans = solve(N, x, y, left - 1, npath);

    if (nans < ans) {
        ans = nans;
        path = npath;
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << path[i];
    }

    cout << "\n";
}