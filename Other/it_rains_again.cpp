#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int cnt[MAX] = {0};
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cnt[x1]++;
        cnt[x2]--;
    }

    int ans = 0;
    for (int i = 1; i < MAX; i++) {
        cnt[i] += cnt[i - 1];
        ans += cnt[i] > 0;
    }

    cout << ans << "\n";
}