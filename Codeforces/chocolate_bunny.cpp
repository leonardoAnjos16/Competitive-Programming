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

const int MAX = 1e4 + 5;

int main() {
    int n; cin >> n;

    set<int> rem;
    for (int i = 1; i <= n; i++)
        rem.insert(i);

    int l = 0, r = 1, p[MAX];
    for (int i = 1; i < n; i++) {
        cout << "? " << (l + 1) << " " << (r + 1) << "\n\n";
        int x; cin >> x;

        cout << "? " << (r + 1) << " " << (l + 1) << "\n\n";
        int y; cin >> y;

        if (y > x) {
            p[r++] = y;
            rem.erase(y);
        } else {
            p[l] = x;
            l = r + 1;
            swap(l, r);
            rem.erase(x);
        }
    }

    p[l] = *rem.begin();
    cout << "!";

    for (int i = 0; i < n; i++)
        cout << " " << p[i];

    cout << "\n";
}