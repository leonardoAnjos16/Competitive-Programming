#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            int A;
            cin >> A;
            sum += A;
        }

        ans = min(ans, 2 * sum);
    }

    cout << ans << "\n";
}