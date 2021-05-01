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

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;

        string X[MAX];
        for (int i = 0; i < N; i++)
            cin >> X[i];

        int ans = 0;
        for (int i = 1; i < N; i++) {
            int n = size(X[i]), m = size(X[i - 1]);
            if (n > m || (n == m && X[i] > X[i - 1])) continue;

            if (X[i] == X[i - 1]) X[i] += '0', ans++;
            else if (X[i] > X[i - 1]) while (size(X[i]) < m) X[i] += '0', ans++;
            else {
                int mx = 0;
                string s = "", t = "";

                for (int j = 0; j < n && s == t; j++) {
                    s += X[i][j];
                    t += X[i - 1][j];

                    if (s == t) mx++;
                    else break;
                }

                if (mx < n) while (size(X[i]) <= m) X[i] += '0', ans++;
                else {
                    ans += m - n;
                    X[i] = X[i - 1];

                    bool done = false;
                    for (int j = m - 1; j >= n && !done; j--)
                        if (X[i][j] < '9') {
                            X[i][j]++;
                            for (int k = j + 1; k < m; k++)
                                X[i][j] = '0';

                            done = true;
                        }

                    if (!done) {
                        for (int j = n; j < m; j++)
                            X[i][j] = '0';

                        X[i] += '0', ans++;
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}