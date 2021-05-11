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

const int MAX = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        string p; cin >> p;
        int n; cin >> n;

        string list; cin >> list;

        int x[MAX], idx = 0;
        string aux = "";

        for (int i = 1; i < size(list); i++) {
            if (list[i] >= '0' && list[i] <= '9') aux += list[i];
            else if (!aux.empty()) x[idx++] = stoi(aux), aux = "";
        }

        int l = 0, r = n - 1;
        bool reversed = false;

        for (char c: p) {
            if (c == 'R') reversed = !reversed;
            else if (reversed) r--;
            else l++;
        }

        if (l - r > 1) cout << "error\n";
        else {
            if (reversed) reverse(x + l, x + r + 1);

            cout << "[";
            for (int i = l; i <= r; i++) {
                if (i > l) cout << ",";
                cout << x[i];
            }

            cout << "]\n";
        }
    }
}