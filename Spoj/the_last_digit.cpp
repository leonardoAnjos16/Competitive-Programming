#include <bits/stdc++.h>

using namespace std;

#define size(ds) (int) (ds).size()
#define vi vector<int>
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        vi digs;
        int cnt[10] = {0};

        int last = a % 10;
        while (!cnt[last]) {
            digs.pb(last);
            cnt[last]++;
            last *= a;
            last %= 10;
        }

        int ans = !b ? 1 : digs[(b - 1) % size(digs)];
        cout << ans << "\n";
    }
}