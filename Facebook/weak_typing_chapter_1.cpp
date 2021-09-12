#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        string W; cin >> W;

        int left = 0;
        bool lhand = true;

        for (int i = 0; i < N; i++) {
            if (W[i] == 'O' && lhand) lhand = false, left++;
            else if (W[i] == 'X' && !lhand) lhand = true, left++;
        }

        int right = 0;
        lhand = false;

        for (int i = 0; i < N; i++) {
            if (W[i] == 'O' && lhand) lhand = false, right++;
            else if (W[i] == 'X' && !lhand) lhand = true, right++;
        }

        int ans = min(left, right);
        cout << "Case #" << t << ": " << ans << "\n";
    }
}