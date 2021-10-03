#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, k;
vector<int> r;
vector<int> memo;

int rocks(int i = 0) {
    if (i >= N) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = rocks(i + 1);
    ans = max(ans, r[i] + rocks(i + k + 1));
    ans = max(ans, r[i] / 2 + rocks(i + k / 2 + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> k;

    r.resize(N);
    for (int i = 0; i < N; i++)
        cin >> r[i];

    memo.assign(N + 5, -1);

    int ans = rocks();
    cout << ans << "\n";
}