#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MOD = 1e9 + 7;

int M, N;
vector<int> notes;
vector<int> memo;

int count(int sum = 0) {
    // cout << "sum: " << sum << "\n";
    if (sum > M) return 0;
    if (sum == M) return 1;

    int &ans = memo[sum];
    if (~ans) return ans;

    ans = 0;
    for (int i = 0; i < N; i++) {
        ans += count(sum + notes[i]);
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    M <<= 2;

    notes.resize(N);
    for (int i = 0; i < N; i++)
        cin >> notes[i];

    memo.assign(M + 5, -1);

    int ans = count();
    cout << ans << "\n";
}