#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> a, memo;

int problems(int i) {
    int &ans = memo[i];
    if (~ans) return ans;

    int nxt = upper_bound(a.begin(), a.end(), 2 * a[i]) - a.begin() - 1;
    if (nxt == i) return 1;

    return nxt - i + problems(nxt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    memo.assign(n + 5, -1);

    int ans = 1;
    for (int i = 0; i < n; i++)
        ans = max(ans, problems(i));

    cout << ans << "\n";
}