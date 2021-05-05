#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 105;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vi aux;
        for (int i = 1; i <= 2; i++)
            for (int j = i; j <= n * n; j += 2)
                aux.pb(j);

        int ans[MAX][MAX], idx = 0;
        for (int i = 1; i < 2 * n; i++) {
            int row = i <= n ? 0 : i - n;
            int col = i <= n ? i - 1 : n - 1;

            while (row < n && col >= 0)
                ans[row++][col--] = aux[idx++];
        }

        bool possible = true;
        for (int i = 0; i < n && possible; i++)
            for (int j = 0; j < n && possible; j++) {
                if (i - 1 >= 0 && abs(ans[i][j] - ans[i - 1][j]) == 1) possible = false;
                if (i + 1 < n && abs(ans[i][j] - ans[i + 1][j]) == 1) possible = false;

                if (j - 1 >= 0 && abs(ans[i][j] - ans[i][j - 1]) == 1) possible = false;
                if (j + 1 < n && abs(ans[i][j] - ans[i][j + 1]) == 1) possible = false;
            }

        if (!possible) cout << "-1\n";
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (j) cout << " ";
                    cout << ans[i][j];
                }

                cout << "\n";
            }
        }
    }
}