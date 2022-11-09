#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int twos = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            while (!(a & 1)) {
                twos++;
                a >>= 1;
            }
        }

        priority_queue<int> heap;
        for (int i = 2; i <= n; i += 2) {
            int aux = i, cnt = 0;
            while (!(aux & 1)) {
                cnt++;
                aux >>= 1;
            }

            heap.push(cnt);
        }

        int ans = 0;
        while (!heap.empty() && twos < n) {
            ans++;
            twos += heap.top();
            heap.pop();
        }

        if (twos < n) cout << "-1\n";
        else cout << ans << "\n";
    }
}