#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, K;
vector<int> h;
vector<int> memo;

int cost(int i = 0) {
    if (i + 1 >= N) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = INT_MAX;
    for (int j = 1; j <= K && i + j < N; j++)
        ans = min(ans, abs(h[i + j] - h[i]) + cost(i + j));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    h.resize(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    memo.assign(N + 5, -1);

    int ans = cost();
    cout << ans << "\n";
}