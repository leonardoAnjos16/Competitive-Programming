#include <bits/stdc++.h>

using namespace std;

#define long long long int

int n, k;
vector<int> h;

long water() {
    long ans = 0LL;
    vector<int> l, r;

    l.resize(n);
    l[0] = h[0];

    for (int i = 1; i < n; i++)
        l[i] = max(l[i - 1], h[i]);

    r.resize(n);
    r[n - 1] = h[n - 1];

    for (int i = n - 2; i >= 0; i--)
        r[i] = max(r[i + 1], h[i]);

    for (int i = 0; i < n; i++)
        ans += min(l[i], r[i]) - h[i];

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    long ans = water();
    for (int t1 = 0; t1 < n; t1++)
        for (int t2 = t1 + 1; t2 < n; t2++)
            for (int t3 = t2 + 1; t3 < n; t3++)
                for (int q1 = 0; q1 <= k; q1++)
                    for (int q2 = 0; q1 + q2 <= k; q2++) {
                        int q3 = k - q2 - q1;

                        h[t1] += q1;
                        h[t2] += q2;
                        h[t3] += q3;

                        ans = max(ans, water());

                        h[t1] -= q1;
                        h[t2] -= q2;
                        h[t3] -= q3;
                    }

    cout << ans << "\n";
}