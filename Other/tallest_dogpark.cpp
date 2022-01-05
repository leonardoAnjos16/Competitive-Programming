#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L; cin >> L;

    if (L == 1) cout << "0\n";
    else {
        int ans = (L - 1) / 2;
        cout << ans << "\n";
    }
}