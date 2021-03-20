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

vector<vi> g;
int N, ds[MAX], sz[MAX];

void build() {
    for (int i = 0; i < N; i++)
        ds[i] = i, sz[i] = 1;
}

int find(int i) {
    if (ds[i] == i) return i;
    return ds[i] = find(ds[i]);
}

void join(int i, int j) {
    i = find(i); j = find(j);
    if (sz[i] < sz[j]) swap(i, j);
    if (i != j) sz[i] += sz[j];
    ds[j] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> N >> M;

    build();
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        join(A - 1, B - 1);
    }

    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
        ans = max(ans, sz[i]);

    cout << ans << "\n";
}