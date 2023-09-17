#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        pos[p - 1] = i;
    }

    int groups = 0, last = N;
    for (int i = 0; i < N; i++) {
        if (pos[i] < last)
            groups++;

        last = pos[i];
    }

    int ans = __lg(groups);
    if ((1 << ans) < groups) ans++;
    cout << ans << "\n";
}