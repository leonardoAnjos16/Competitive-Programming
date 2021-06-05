#include <bits/stdc++.h>

using namespace std;

#define long long long int

vector<int> a;
vector<vector<long>> memo;

long diff(int i, int j) {
    if (i > j) return 0LL;

    long &ans = memo[i][j];
    if (~ans) return ans;

    return ans = max(a[i] - diff(i + 1, j), a[j] - diff(i, j - 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    a.resize(N);
    long sum = 0LL;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    memo.assign(N + 5, vector<long>(N + 5, -1LL));

    long ans = diff(0, N - 1);
    cout << ans << "\n";
}