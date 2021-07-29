#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    array<int, 3> a;
    for (int i = 0; i < 3; i++)
        cin >> a[i];

    array<int, 3> b;
    for (int i = 0; i < 3; i++)
        cin >> b[i];

    int mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);

    a[0] -= min(a[0], b[0] + b[2]);
    a[1] -= min(a[1], b[1] + b[0]);
    a[2] -= min(a[2], b[2] + b[1]);

    int mn = a[0] + a[1] + a[2];

    cout << mn << " " << mx << "\n";
}