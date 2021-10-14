#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int INF = 1e9 + 5;

int n;
vector<tuple<int, int, int>> projects;
vector<long> memo;

long money(int i = 0) {
    if (i >= n) return 0;

    long &ans = memo[i];
    if (~ans) return ans;

    ans = money(i + 1);

    auto [a, b, p] = projects[i];
    int nxt = upper_bound(projects.begin(), projects.end(), make_tuple(b, INF, INF)) - projects.begin();
    ans = max(ans, money(nxt) + p);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    projects.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        projects[i] = make_tuple(a, b, p);
    }

    sort(projects.begin(), projects.end());
    memo.assign(n + 5, -1);

    long ans = money();
    cout << ans << "\n";
}