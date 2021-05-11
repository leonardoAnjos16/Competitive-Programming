#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define rall(ds) (ds).rbegin(), (ds).rend()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

const int MAX = 5e3 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    while (cin >> n, n) {
        if (cnt++) cout << "\n";

        pii a[MAX];
        for (int i = 0; i < n; i++) {
            int v; cin >> v;
            a[i] = { v, i };
        }

        pii ans[MAX];
        for (int i = 0; i < n; i++)
            cin >> ans[i].fst;

        sort(a, a + n);
        sort(ans, ans + n);

        for (int i = 0; i < n; i++) {
            ans[i].snd = a[i].snd;
            swap(ans[i].fst, ans[i].snd);
        }

        sort(ans, ans + n);
        for (int i = 0; i < n; i++)
            cout << ans[i].snd << "\n";
    }
}