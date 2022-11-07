#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.rbegin(), a.rend());

    int ans = 0;
    for (int i = 0; i < K; i++)
        ans += a[i];

    cout << ans << "\n";
}