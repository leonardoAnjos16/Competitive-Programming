#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K; cin >> K;

    long ans = (1LL << (K + 1)) - 1LL;
    cout << ans << "\n";
}