#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int k = n / 2 + 1;
    cout << k << "\n";

    for (int i = 1; i <= n; i += 2) {
        if (i > 1) cout << " ";
        cout << i;
    }

    if (!(n & 1))
        cout << " " << n;
    
    cout << "\n";
}