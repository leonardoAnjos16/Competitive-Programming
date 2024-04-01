#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

vector<vector<int>> memo;

int strength(int last, int available) {
    if (!available) return 0;

    int &ans = memo[last][available];
    if (~ans) return ans;

    for (int i = 0; i < MAX; i++)
        if (available & (1 << i))
            ans = max(ans, gcd(last, i + 1) + strength(i + 1, available ^ (1 << i)));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> A(N);
    int cnt[MAX] = {0};

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i] - 1]++;
    }

    int available = 0, ans = 0;
    for (int i = 0; i < MAX; i++)
        if (cnt[i]) {
            available |= 1 << i;
            ans += (i + 1) * (cnt[i] - 1);
        }

    memo.assign(MAX + 5, vector<int>((1 << MAX) + 5, -1));

    int best = INT_MIN;
    for (int i = 0; i < MAX; i++)
        if (cnt[i])
            best = max(best, strength(i + 1, available ^ (1 << i)));

    ans += best;
    cout << ans << "\n";
}