#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int px, py; cin >> px >> py;
        string s; cin >> s;

        sort(all(s));

        char letter = px < 0 ? 'L' : 'R';
        bool possible = upper_bound(all(s), letter) - lower_bound(all(s), letter) >= abs(px);

        letter = py < 0 ? 'D' : 'U';
        possible &= upper_bound(all(s), letter) - lower_bound(all(s), letter) >= abs(py);

        cout << (possible ? "YES" : "NO") << "\n";
    }
}