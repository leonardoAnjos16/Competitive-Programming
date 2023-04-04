#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int INF = 1e6 + 5;

vector<int> memo;

int complexity(int n) {
    if (!n) return INF;

    int &ans = memo[n];
    if (~ans) return ans;

    ans = n;

    int p = 10;
    while (p <= n) {
        if ((n % p) / (p / 10) > 0)
            ans = min(ans, complexity(n / p) + complexity(n % p));

        p *= 10;
    }

    for (int i = 2; i * i <= n; i++)
        if (!(n % i))
            ans = min(ans, complexity(i) + complexity(n / i));

    for (int i = 1; i <= n / 2; i++)
        ans = min(ans, complexity(i) + complexity(n - i));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    memo.assign(n + 5, -1);

    int ans = complexity(n);
    cout << ans << "\n";
}