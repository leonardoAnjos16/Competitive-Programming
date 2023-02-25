#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N);
    for (int i = 1; i < N; i++)
        cin >> a[i];

    vector<int> x(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> x[i];

    vector<llong> l(N + 1, 0LL);
    for (int i = 2; i <= N; i++)
        l[i] = l[i - 1] + x[i - 1] + a[i - 1];

    vector<llong> r(N + 1, 0LL);
    for (int i = N - 1; i > 0; i--)
        r[i] = r[i + 1] + x[i + 1] + a[i];

    llong ans = 0LL;
    for (int i = 1; i <= N; i++) {
        if (l[i] + x[i] < r[i] || l[i] > r[i] + x[i]) continue;
        ans += min(l[i] + x[i], r[i] + x[i]) - max(l[i], r[i]);
    }

    cout << ans << "\n";
}