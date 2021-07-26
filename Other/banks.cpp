#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("A.in", "r", stdin);

    int n; cin >> n;

    int cnt = 0;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) cnt++;
    }

    int ans = 0;
    while (cnt) {
        int idx = -1;
        for (int i = 0; i < n; i++)
            if (a[i] < 0 && (idx == -1 || a[i] > a[idx]))
                idx = i;

        ans++; cnt--;
        a[idx] = -a[idx];

        bool neg = a[(idx + 1) % n] < 0;
        a[(idx + 1) % n] -= a[idx];
        if (!neg && a[(idx + 1) % n] < 0) cnt++;

        neg = a[(idx - 1 + n) % n] < 0;
        a[(idx - 1 + n) % n] -= a[idx];
        if (!neg && a[(idx - 1 + n) % n] < 0) cnt++;
    }

    cout << ans << "\n";
}