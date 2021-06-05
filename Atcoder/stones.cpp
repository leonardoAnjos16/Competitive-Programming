#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> a;
vector<int> memo;

int player_wins(int K) {
    int &ans = memo[K];
    if (ans) return ans;

    ans = -1;
    for (int i = 0; i < N && a[i] <= K && ans < 0; i++)
        if (player_wins(K - a[i]) < 0) ans = 1;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    cin >> N >> K;

    a.resize(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    memo.assign(K + 5, 0);

    bool ans = player_wins(K) > 0;
    if (ans) cout << "First\n";
    else cout << "Second\n";
}