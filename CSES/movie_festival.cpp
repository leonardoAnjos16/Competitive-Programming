#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int n;
vector<pair<int, int>> movies;
vector<int> memo;

int watch(int i = 0) {
    if (i >= n) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = watch(i + 1);

    auto [a, b] = movies[i];
    auto it = lower_bound(movies.begin(), movies.end(), make_pair(b, 0));

    return ans = max(ans, watch(it - movies.begin()) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    movies.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = make_pair(a, b);
    }

    sort(movies.begin(), movies.end());

    memo.assign(n + 5, -1);

    int ans = watch();
    cout << ans << "\n";
}