#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        string city[3];
        for (int i = 0; i < 3; i++)
            cin >> city[i];

        int ans = 0;
        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    if (city[j][3 * i + k] == '*')
                        cnt++;

            ans = max(ans, 4 * cnt);
        }

        cout << ans << "\n";
    }
}