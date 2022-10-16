#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> p(n);
    long long int sum = 0LL;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }

    long long int ans = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++) {
        long long int group = 0LL;
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                group += p[j];

        ans = min(ans, abs(2 * group - sum));
    }

    cout << ans << "\n";
}