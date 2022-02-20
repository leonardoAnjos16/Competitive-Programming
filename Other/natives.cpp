#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int sum = 0;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n / 2; i++)
        sum -= a[i];

    if (n & 1) sum -= a[n / 2];
    cout << sum << "\n";
}