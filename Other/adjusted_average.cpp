#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double

ldouble mean(llong s, int n) {
    return 1.0L * s / n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << setprecision(6) << fixed;

    int n, k, x;
    cin >> n >> k >> x;

    llong sum = 0LL;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    ldouble ans = abs(mean(sum, n) - x), curr;
    for (int i = 0; i < n; i++)
        if ((curr = abs(mean(sum - a[i], n - 1) - x)) < ans)
            ans = curr;

    if (k >= 2) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((curr = abs(mean(sum - a[i] - a[j], n - 2) - x)) < ans)
                    ans = curr;
    }

    if (k >= 3) {
        set<llong> sums;
        for (int i = 0; i < n; i++) {
            auto it = sums.upper_bound(sum - a[i] - (n - 3LL) * x);
            if (it != sums.end() && (curr = abs(mean(sum - *it - a[i], n - 3) - x)) < ans)
                ans = curr;

            if (it != sums.begin() && (curr = abs(mean(sum - *(--it) - a[i], n - 3) - x)) < ans)
                ans = curr;

            for (int j = 0; j < i; j++)
                sums.insert(a[j] + a[i]);
        }
    }

    if (k >= 4) {
        set<llong> sums;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto it = sums.upper_bound(sum - a[i] - a[j] - (n - 4LL) * x);
                if (it != sums.end() && (curr = abs(mean(sum - *it - a[i] - a[j], n - 4) - x)) < ans)
                    ans = curr;

                if (it != sums.begin() && (curr = abs(mean(sum - *(--it) - a[i] - a[j], n - 4) - x)) < ans)
                    ans = curr;
            }

            for (int j = 0; j < i; j++)
                sums.insert(a[j] + a[i]);
        }
    }

    cout << ans << "\n";
}