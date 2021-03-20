#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int INF = 1e9;
const int MAX = 1e3 + 5;

int N, M;
vector<vi> A, dists;

void get_dists() {
    vector<bitset<MAX>> vis(N, bitset<MAX>());
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dists[i][j] = INF;

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push({ A[0][0], { 0, 0 } });

    dists[0][0] = A[0][0];
    for (int i = 0; i < N * M; i++) {
        pii v;
        do {
            if (pq.empty()) return;
            v = pq.top().snd; pq.pop();
        } while (vis[v.fst][v.snd]);

        vis[v.fst][v.snd] = true;
        for (int j = -1; j <= 1; j++)
            for (int k = -1; k <= 1; k++) {
                if (j && k) continue;

                pii u = { v.fst + j, v.snd + k };
                if (u.fst < 0 || u.fst >= N || u.snd < 0 || u.snd >= M) continue;

                if (!vis[u.fst][u.snd] && dists[v.fst][v.snd] + A[u.fst][u.snd] < dists[u.fst][u.snd]) {
                    dists[u.fst][u.snd] = dists[v.fst][v.snd] + A[u.fst][u.snd];
                    pq.emplace(dists[u.fst][u.snd], u);
                }
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        cin >> N >> M;

        A.assign(N, vi(M));
        dists.assign(N, vi(M));

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];

        get_dists();

        int ans = dists[N - 1][M - 1];
        cout << ans << "\n";

        A.clear();
        dists.clear();
    }
}