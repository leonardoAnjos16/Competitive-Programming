#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> T;
vector<int> memo;

int seconds(int i = 0) {
    if (i >= N) return 0;

    int &ans = memo[i];
    if (~ans) return ans;

    ans = INT_MAX;
    for (int j = i; j < N; j++)
        ans = min(ans, seconds(j + 1) + max(T[j] - T[i] - 30 * 60 + 20, 20 * (j - i + 1)) + 120);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    T.resize(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    memo.assign(N, -1);

    int ans = seconds();
    cout << ans << "\n";
}