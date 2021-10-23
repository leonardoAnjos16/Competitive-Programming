#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, C, T1, T2;
vector<bool> hole;
vector<int> memo;

int length(int dist = 0) {
    if (dist >= C) return 0;

    int &ans = memo[dist];
    if (~ans) return ans;

    ans = T1 + length(dist + T1 + 1);
    ans = min(ans, T2 + length(dist + T2 + 1));
    if (!hole[dist]) ans = min(ans, length(dist + 1));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C >> T1 >> T2;

    hole.assign(C, false);
    for (int i = 0; i < N; i++) {
        int F; cin >> F;
        hole[F] = true;
    }

    memo.assign(C + 5, -1);

    int ans = length();
    cout << ans << "\n";
}