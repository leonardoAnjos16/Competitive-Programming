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

int *sequence(int N, int C) {
    if (C < N - 1 || C > N * (N + 1) / 2 - 1) return NULL;
    if (N == 1) {
        int *ans = new int[1];
        ans[0] = 1;
        return ans;
    }

    for (int i = 0; i < N; i++) {
        int *nxt = sequence(N - 1, C - i - 1);
        if (nxt != NULL) {
            int *ans = new int[N];
            ans[0] = 1;

            for (int j = 1; j < N; j++)
                ans[j] = nxt[j - 1] + 1;

            reverse(ans, ans + i + 1);
            delete [] nxt;
            return ans;
        }
    }

    return NULL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, C;
        cin >> N >> C;

        cout << "Case #" << t << ":";

        int *ans = sequence(N, C);
        if (ans == NULL) cout << " IMPOSSIBLE\n";
        else {
            for (int i = 0; i < N; i++)
                cout << " " << ans[i];

            cout << "\n";
            delete [] ans;
        }
    }
}