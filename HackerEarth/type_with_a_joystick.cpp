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

    string s; cin >> s;

    set<pii> used;
    map<char, pii> ctp;

    used.emplace(0, 0);
    ctp[s[0]] = mp(0, 0);

    for (int i = 1; i < size(s); i++) {
        if (ctp.count(s[i])) continue;
        pii aux = ctp[s[i - 1]];

        queue<pii> points;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if ((j && k) || !(j || k)) continue;
                points.push(mp(aux.fst + j, aux.snd + k));
            }
        }

        set<pii> vis;
        bool done = false;

        while (!done) {
            pii p = points.front(); points.pop();
            if (!used.count(p)) {
                used.insert(p);
                ctp[s[i]] = p;
                done = true;
            } else {
                for (int j = -1; j <= 1; j++) {
                    for (int k = -1; k <= 1; k++) {
                        if ((j && k) || !(j || k)) continue;
                        pii np = mp(p.fst + j, p.snd + k);
                        if (!vis.count(np)) {
                            vis.insert(np);
                            points.push(np);
                        }
                    }
                }
            }
        }
    }

    srand(time(NULL));
    for (char c = 'a'; c <= 'z'; c++) {
        if (ctp.count(c)) cout << ctp[c].fst << " " << ctp[c].snd << "\n";
        else {
            int x, y;
            do x = rand() % 1000, y = rand() % 1000;
            while (used.count(mp(x, y)));

            cout << x << " " << y << "\n";
        }
    }
}