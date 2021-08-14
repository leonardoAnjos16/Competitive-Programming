#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    int mx = INT_MIN;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int idx = 0;
    long extra = 0LL;

    while (K > 0) {
        if (a[idx] < mx) {
            K--;
            extra += a[idx] - 1;
        } else if (extra >= K) {
            cout << "YES\n";
            return 0;
        } else {
            K -= mx;
        }

        idx = (idx + 1) % N;
    }

    cout << (a[idx] < mx ? "KEK" : "YES") << "\n";
}