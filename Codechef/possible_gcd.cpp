#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;

        if (A < B) swap(A, B);

        int ans = 0;
        for (int i = 1; i * i <= A - B; i++)
            if ((A - B) % i == 0) {
                if (i * i < A - B) ans += 2;
                else ans++;
            }

        cout << ans << "\n";
    }
}