#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long p; cin >> p;

    vector<int> ans(p, -1);
    for (long i = 0; i < p; i++) {
        long m = (i * i) % p;
        ans[m] = i;
    }

    for (int i = 0; i < p; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}