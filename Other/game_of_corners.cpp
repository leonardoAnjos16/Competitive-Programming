#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, m;
    cin >> n >> m;

    if (n > m) swap(n, m);
    
    long ans = n * (m + 1);
    cout << ans << "\n";
}