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

    sort(x.begin(), x.end());

    int ans = 1;
    for (int i = 1; i < n; i++)
        if (x[i] != x[i - 1])
            ans++;

    cout << ans << "\n";
}