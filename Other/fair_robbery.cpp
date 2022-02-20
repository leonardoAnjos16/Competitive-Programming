#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(9) << fixed;

    int n; cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> mnl(n + 1, INT_MAX), mxl(n + 1, INT_MIN);
    for (int i = 1; i <= n; i++) {
        mnl[i] = min(mnl[i - 1], a[i]);
        mxl[i] = max(mxl[i - 1], a[i]);
    }

    vector<int> mnr(n + 2, INT_MAX), mxr(n + 2, INT_MIN);
    for (int i = n; i > 0; i--) {
        mnr[i] = min(mnr[i + 1], a[i]);
        mxr[i] = max(mxr[i + 1], a[i]);
    }

    vector<long double> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        long double l = 0.0L, r = 1.0L;
        while (r - l > EPS) {
            long double t1 = l + (r - l) / 3.0L;
            long double t2 = r - (r - l) / 3.0L;

            long double mn1 = min(1.0L * mnl[i - 1], (1.0L - t1) * mnr[i]);
            long double mx1 = max(1.0L * mxl[i - 1], (1.0L - t1) * mxr[i]);
            long double u1 = mx1 - mn1;

            long double mn2 = min(1.0L * mnl[i - 1], (1.0L - t2) * mnr[i]);
            long double mx2 = max(1.0L * mxl[i - 1], (1.0L - t2) * mxr[i]);
            long double u2 = mx2 - mn2;

            if (u1 < u2) r = t2;
            else l = t1;
        }

        ans[i] = l;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}