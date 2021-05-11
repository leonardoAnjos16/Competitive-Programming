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

const int MAX = 2e5 + 5;
const long INF = 8e18;

long cost[10];
map<string, long> dists;

void get_dists(string &s) {
    set<string> vis;

    string aux = "012345678";
    do dists[aux] = INF;
    while (next_permutation(all(aux)));

    pq<pair<long, string>, vector<pair<long, string>>, greater<pair<long, string>>> heap;
    heap.emplace(0LL, s);

    dists[s] = 0LL;
    while (!heap.empty()) {
        string v = heap.top().snd; heap.pop();
        if (vis.count(v)) continue;
        vis.insert(v);

        int idx = 0;
        while (v[idx] != '0') idx++;

        vi moves;
        if (idx % 3) moves.pb(idx - 1);
        if (idx % 3 < 2) moves.pb(idx + 1);
        if (idx / 3) moves.pb(idx - 3);
        if (idx / 3 < 2) moves.pb(idx + 3);

        long curr_dist = dists[v];
        for (auto move: moves) {
            swap(v[move], v[idx]);
            if (!vis.count(v) && curr_dist + cost[v[idx] - '0'] < dists[v]) {
                dists[v] = curr_dist + cost[v[idx] - '0'];
                heap.emplace(dists[v], v);
            }

            swap(v[move], v[idx]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            s += c;
        }
    }

    for (int i = 1; i <= 8; i++)
        cin >> cost[i];

    get_dists(s);

    long ans = dists["123456780"];
    cout << ans << "\n";
}