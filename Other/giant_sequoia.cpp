#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> fbest(n), fsuff(n);
    fbest[0] = fsuff[0] = 1;

    for (int i = 1; i < n; i++) {
        fsuff[i] = a[i] > a[i - 1] ? fsuff[i - 1] + 1 : 1;
        fbest[i] = max(fbest[i - 1], fsuff[i]);
    }

    vector<int> bbest(n), bpref(n);
    bbest[n - 1] = bpref[n - 1] = 1;

    for (int i = n - 2; i >= 0; i--) {
        bpref[i] = a[i] < a[i + 1] ? bpref[i + 1] + 1 : 1;
        bbest[i] = max(bbest[i + 1], bpref[i]);
    }

    int ans = fbest[n - 1];
    if (k < n) ans = max({ ans, bbest[k], fbest[n - k - 1] });

    for (int i = k; i < n - 1; i++) {
        ans = max({ ans, fbest[i - k], bbest[i + 1] });
        if (a[i - k] < a[i + 1]) ans = max(ans, fsuff[i - k] + bpref[i + 1]);
    }

    cout << ans << "\n";
}