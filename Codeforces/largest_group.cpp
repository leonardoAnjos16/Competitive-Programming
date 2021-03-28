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

const int MAX = 20;

int P, relations[MAX];
short int memo[MAX][1 << MAX];

short int group(int i = 0, int boys = 0) {
    if (i >= P) {
        int girls = (1 << P) - 1, cnt = 0;
        for (int j = 0; j < P; j++)
            if (boys & (1 << j))
                girls &= relations[j], cnt++;

        for (int j = 0; j < P; j++)
            if (girls & (1 << j)) cnt++;

        return cnt;
    }

    short int &ans = memo[i][boys];
    if (~ans) return ans;

    return ans = max(group(i + 1, boys), group(i + 1, boys | (1 << i)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N;
        cin >> P >> N;

        memset(relations, 0, sizeof relations);
        for (int i = 0; i < N; i++) {
            int b, g;
            cin >> b >> g;
            relations[--b] |= (1 << --g);
        }

        memset(memo, -1, sizeof memo);

        int ans = group();
        cout << ans << "\n";
    }
}