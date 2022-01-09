#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    set<int> days;
    for (int i = 0; i < n; i++)
        days.insert((p[i] + c[i]) % k);

    bool possible = (int) days.size() == n;
    for (auto d: days)
        if (d >= n) possible = false;

    cout << (possible ? "S" : "N") << "\n";
}