#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> C(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int c; cin >> c;
            C[i] += c;
        }

    sort(C.begin(), C.end());

    llong sum = 0LL;
    for (int i = 0; i < n; i++)
        sum += C[i];

    llong ans = sum;
    for (int i = 0; i < n / 2; i++)
        ans -= 2LL * C[i];

    ans /= 2LL;
    cout << ans << "\n";
}