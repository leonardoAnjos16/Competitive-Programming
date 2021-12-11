#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s.rbegin(), s.rend());

    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (i < n / 2) a += s[i];
        else b += s[i];
    }

    long double prob = 1.0L / (1.0L + powl(10.0L, (b - a) / 400.0L));
    cout << a << " " << prob << "\n";
}