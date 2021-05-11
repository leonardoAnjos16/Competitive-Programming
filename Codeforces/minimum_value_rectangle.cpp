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

const int MAX = 1e4 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;

        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }

        int a = 0, b = INT_MAX, last = 0;
        for (auto p: cnt) {
            if (p.snd >= 4) a = b = p.fst;
            else if (p.snd >= 2) {
                if (last && (p.fst + .0) / last + last / (p.fst + .0) < b / (a + .0) + (a + .0) / b)
                    a = last, b = p.fst;

                last = p.fst;
            }
        }

        cout << a << " " << a << " " << b << " " << b << "\n";
    }
}