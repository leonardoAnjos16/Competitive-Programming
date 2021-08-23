#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        int cnt = 0;
        while (a[i]) {
            if (a[i] & 1)
                cnt++;

            a[i] >>= 1;
        }

        a[i] = cnt;
    }

    long ans = 0LL;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        ans += cnt[a[i]];
        cnt[a[i]]++;
    }

    cout << ans << "\n";
}