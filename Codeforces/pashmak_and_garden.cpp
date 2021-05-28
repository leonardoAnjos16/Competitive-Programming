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

const int MAX = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    bool possible = true;

    if (x1 == x2) x3 = x4 = x1 + abs(y2 - y1), y3 = y1, y4 = y2;
    else if (y1 == y2) x3 = x1, x4 = x2, y3 = y4 = y1 + abs(x2 - x1);
    else if (abs(x2 - x1) == abs(y2 - y1)) x3 = x1, y3 = y2, x4 = x2, y4 = y1;
    else possible = false;

    if (!possible) cout << "-1\n";
    else cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
}