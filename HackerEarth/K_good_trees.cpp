#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int M;
        cin >> M;
        M--;

        int ans = 0;
        for (int i = 1; i * i <= M; i++)
            if (!(M % i)) {
                ans++;
                if (i * i < M)
                    ans++;
            }

        cout << ans << "\n";
    }
}