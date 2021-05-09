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

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    long v[MAX] = {0}, aux[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        aux[i] = v[i];
    }

    sort(aux + 1, aux + n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
        aux[i] += aux[i - 1];
    }

    int m; cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        long *arr = type == 1 ? v : aux;
        long ans = arr[r] - arr[l - 1];
        cout << ans << "\n";
    }
}