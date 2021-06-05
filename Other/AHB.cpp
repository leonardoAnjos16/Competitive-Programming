#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;

    long ans = 0LL;
    for (int i = 0, n = A.size(); i < n; i++) {
        ans *= 10LL;
        ans += abs(A[i] - B[i]);
    }

    cout << ans << "\n";
}