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

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int a[MAX];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n - 1 && k; i++) {
            int aux = min(a[i], k);
            a[i] -= aux;
            a[n - 1] += aux;
            k -= aux;
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << "\n";
    }
}