#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N;
vector<int> h;
vector<int> memo;

int cost(int i = 0) {
    if (i + 1 >= N) return 0;
    if (i + 2 >= N) return abs(h[i + 1] - h[i]);

    int &ans = memo[i];
    if (~ans) return ans;

    return ans = min(abs(h[i + 1] - h[i]) + cost(i + 1), abs(h[i + 2] - h[i]) + cost(i + 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    h.resize(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    memo.assign(N + 5, -1);

    int ans = cost();
    cout << ans << "\n";
}