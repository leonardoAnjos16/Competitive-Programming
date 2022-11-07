#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    int ans = 0;
    long long int sum = 1LL;

    while (sum < n) {
        ans++;
        sum += sum * k;
    }

    cout << ans << "\n";
}