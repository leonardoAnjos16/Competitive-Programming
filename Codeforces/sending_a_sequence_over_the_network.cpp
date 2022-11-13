#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<int> b;
vector<vector<int>> nxt;
vector<int> memo;

bool possible(int i = 0) {
    if (i > n) return false;
    if (i == n) return true;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = possible(i + b[i] + 1);
    for (int j: nxt[i])
        ans |= possible(j + 1);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        cin >> n;

        b.resize(n);
        nxt.assign(n, vector<int>());

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (i - b[i] >= 0 && i - b[i] < n)
                nxt[i - b[i]].push_back(i);
        }

        memo.assign(n + 5, -1);

        cout << (possible() ? "YES" : "NO") << "\n";
    }
}