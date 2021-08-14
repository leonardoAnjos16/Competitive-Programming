#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    int aux = 8;
    for (int i = 2; i <= n && i < 10; i++)
        aux *= 9;

    string ans = to_string(aux);
    for (int i = 10; i <= n; i++)
        ans += "0";

    cout << ans << "\n";
}