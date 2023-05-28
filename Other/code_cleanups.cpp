#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 400;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    bool dirty[MAX] = {0};
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        dirty[d] = true;
    }

    int cnt = 0, dirtiness = 0, ans = 0;
    for (int i = 1; i <= 365; i++) {
        cnt += dirty[i];
        if (dirtiness + cnt >= 20) {
            ans++;
            cnt = dirtiness = 0;
        }

        dirtiness += cnt;
    }

    if (dirtiness) ans++;
    cout << ans << "\n";
}