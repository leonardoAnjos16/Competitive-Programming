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

int N, M, K;
pii cond[MAX];
pii people[MAX];

int memo[MAX][1 << 16];

int conditions(int i = 0, int chosen = 0) {
    if (i >= K) {
        int cnt[MAX] = {0};
        for (int j = 0; j < K; j++) {
            if (chosen & (1 << j)) cnt[people[j].snd]++;
            else cnt[people[j].fst]++;
        }

        int ans = 0;
        for (int j = 0; j < M; j++)
            if (cnt[cond[j].fst] && cnt[cond[j].snd]) ans++;

        return ans;
    }

    int &ans = memo[i][chosen];
    if (~ans) return ans;

    return ans = max(conditions(i + 1, chosen), conditions(i + 1, chosen | (1 << i)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> cond[i].fst >> cond[i].snd;

    cin >> K;
    for (int i = 0; i < K; i++)
        cin >> people[i].fst >> people[i].snd;

    memset(memo, -1, sizeof memo);

    int ans = conditions();
    cout << ans << "\n";
}