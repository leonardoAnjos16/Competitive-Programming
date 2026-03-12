#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> t1, t2;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (i < MAX) t1.push_back(t);
        else t2.push_back(t);
    }

    vector<int> sums;
    int n1 = t1.size();

    for (int i = 0; i < (1 << n1); i++) {
        llong sum = 0LL;
        for (int j = 0; j < n1; j++)
            if (i & (1 << j))
                sum += t1[j];

        if (sum <= x)
            sums.push_back(sum);
    }

    sort(sums.begin(), sums.end());

    llong ans = 0LL;
    int n2 = t2.size();

    for (int i = 0; i < (1 << n2); i++) {
        llong sum = 0LL;
        for (int j = 0; j < n2; j++)
            if (i & (1 << j))
                sum += t2[j];

        ans += upper_bound(sums.begin(), sums.end(), x - sum) - lower_bound(sums.begin(), sums.end(), x - sum);
    }

    cout << ans << "\n";
}