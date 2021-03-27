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
        int N, C;
        cin >> N >> C;

        cout << "Case #" << t << ":";

        int ans[MAX];
        for (int i = 0; i < N; i++)
            ans[i] = i + 1;

        bool possible = false;
        do {
            int A[MAX];
            for (int i = 0; i < N; i++)
                A[i] = ans[i];

            int cost = 0;
            for (int i = 0; i < N - 1; i++) {
                int idx = i;
                for (int j = i + 1; j < N; j++)
                    if (A[j] < A[idx]) idx = j;

                cost += idx - i + 1;
                reverse(A + i, A + idx + 1);
            }

            if (cost == C) possible = true;
        } while (!possible && next_permutation(ans, ans + N));

        if (!possible) cout << " IMPOSSIBLE\n";
        else {
            for (int i = 0; i < N; i++)
                cout << " " << ans[i];

            cout << "\n";
        }
    }
}