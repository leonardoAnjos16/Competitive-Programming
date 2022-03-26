#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, m;
vector<int> x;
vector<int> memo;

int opponents(int i) {
    if (i >= n) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    return ans = max(opponents(i + 1), opponents(i + m) + x[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    x.resize(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    memo.assign(n + 5, -1);

    int ans = opponents(m);
    cout << ans << "\n";
}