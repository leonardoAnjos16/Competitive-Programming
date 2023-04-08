#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> p(N + 1), h(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> p[i] >> h[i];

    vector<llong> ps(N + 1, 0LL);
    for (int i = 1; i <= N; i++)
        ps[i] = ps[i - 1] + p[i] * h[i];

    llong ans = 0LL;
    for (int i = K; i <= N; i++)
        ans = max(ans, ps[i] - ps[i - K]);

    cout << ans << "\n";
}