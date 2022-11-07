#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    llong ans = LLONG_MIN, sum = 0LL;
    for (int i = 0; i < n; i++) {
        sum += x[i];
        ans = max(ans, sum);
        sum = max(sum, 0LL);
    }

    cout << ans << "\n";
}