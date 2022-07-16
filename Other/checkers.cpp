#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long a, b;
    cin >> a >> b;

    long ans = min(b, a + 1);
    cout << ans << "\n";
}