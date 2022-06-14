#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    string ans = to_string((10 * B) / 2);
    ans += to_string(A);

    cout << ans << "\n";
}