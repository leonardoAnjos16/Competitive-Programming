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

const int MAX = 15;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int G, P;
        cin >> G >> P;

        int X[MAX];
        for (int i = 0; i < 10; i++)
            cin >> X[i];

        int sum = 0;
        for (int i = G; i < 10; i++)
            sum += X[i];

        int mn = (sum + P) / P;
        int mx = (sum + X[G - 1] + P - 1) / P;

        cout << mn << " " << mx << "\n";
    }
}