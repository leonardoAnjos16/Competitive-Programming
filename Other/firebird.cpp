#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int i = N - 2; i >= 0; i--)
        if (a[i] == -1 && a[i + 1] != -1)
            a[i] = a[i + 1] - 1;

    if (a[0] == -1) a[0] = 0;
    for (int i = 1; i < N; i++)
        if (a[i] == -1 && a[i - 1] != -1 && a[i - 1] < K - 1)
            a[i] = a[i - 1] + 1;

    int ans = 0;
    for (int i = 0; i < N; i++)
        if (a[i] == 0) ans++;

    int cnt = 0, idx = 0;
    while (idx < N) {
        while (idx < N && a[idx] != -1) idx++;
        while (idx < N && a[idx] == -1) cnt++, idx++;

        ans += cnt / K;
        if (idx >= N && cnt % K > 0) ans++;
        cnt = 0;
    }

    cout << ans << "\n";
}