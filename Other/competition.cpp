#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    vector<bool> b(2 * N + 1, false);
    for (int i = 0; i < N; i++) {
        int bi; cin >> bi;
        b[bi] = true;
    }

    int idx = 0, ans = 0;
    for (int i = 0; i < N && idx <= 2 * N; i++) {
        while (idx <= a[i] && idx <= 2 * N) idx++;
        while (idx <= 2 * N && !b[idx]) idx++;
        if (idx <= 2 * N) ans++, idx++;
    }

    cout << ans << "\n";
}