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

    int n; cin >> n;

    int ax, ay;
    cin >> ax >> ay;

    int bx, by;
    cin >> bx >> by;

    pii moves[MAX];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        moves[i] = mp(x, y);
    }

    sort(moves, moves + n);
    for (int i = 0; i < n; i++) {
        int x = ax + moves[i].fst;
        int y = ay + moves[i].snd;

        if (x <= 0 || x > n) continue;
        if (y <= 0 || y > n) continue;

        if ((x == bx && y == by) || binary_search(moves, moves + n, mp(bx - x, by - y))) {
            cout << "Alice wins\n";
            return 0;
        }
    }

    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        ax = rand() % n + 1;
        ay = rand() % n + 1;

        if (ax == bx && ay == by) continue;

        bool tie = true;
        for (int j = 0; j < n && tie; j++) {
            int x = bx + moves[j].fst;
            int y = by + moves[j].snd;

            if (x <= 0 || x > n) continue;
            if (y <= 0 || y > n) continue;

            if ((x == ax && y == ay) || binary_search(moves, moves + n, mp(ax - x, ay - y)))
                tie = false;
        }

        if (tie) {
            cout << "tie " << ax << " " << ay << "\n";
            return 0;
        }
    }

    cout << "Bob wins\n";
}