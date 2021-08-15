#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        long ans = 0LL;
        for (int C = 1; C <= N; C++)
            for (int B = 2 * C; B <= N; B += C)
                ans += (N - C) / B + 1;

        cout << ans << "\n";
    }
}