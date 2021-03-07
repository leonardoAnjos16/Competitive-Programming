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

const int MAX = 505;

int h, w, v = 0;
string s[MAX];

pii center;
set<pii> vis;
int degrees[5] = {0};

void get_degrees(int i, int j) {
    if (vis.count({ i, j })) return;

    int ans = 0; v++;
    vis.insert({ i, j });

    if (i > 0 && s[i - 1][j] == '*')
        ans++, get_degrees(i - 1, j);

    if (i + 1 < h && s[i + 1][j] == '*')
        ans++, get_degrees(i + 1, j);

    if (j > 0 && s[i][j - 1] == '*')
        ans++, get_degrees(i, j - 1);

    if (j + 1 < w && s[i][j + 1] == '*')
        ans++, get_degrees(i, j + 1);

    degrees[ans]++;
    if (ans == 4)
        center = { i, j };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> s[i];

    int components = 0;
    for (int i = 0; i < h && components < 2; i++)
        for (int j = 0; j < w && components < 2; j++)
            if (s[i][j] == '*' && !vis.count({ i, j })) {
                components++;
                get_degrees(i, j);
            }

    if (components > 1 || degrees[1] != 4 || degrees[4] != 1 || degrees[2] != v - 5) {
        cout << "NO\n";
        return 0;
    }

    pii t = center, b = center;
    while (t.fst > 0 && s[t.fst - 1][t.snd] == '*') t.fst--;
    while (b.fst + 1 < h && s[b.fst + 1][b.snd] == '*') b.fst++;

    pii l = center, r = center;
    while (l.snd > 0 && s[l.fst][l.snd - 1] == '*') l.snd--;
    while (r.snd + 1 < w && s[r.fst][r.snd + 1] == '*') r.snd++;

    if ((t.snd > 0 && s[t.fst][t.snd - 1] == '*') || (t.snd + 1 < w && s[t.fst][t.snd + 1] == '*'))
        cout << "NO\n";
    else if ((b.snd > 0 && s[b.fst][b.snd - 1] == '*') || (b.snd + 1 < w && s[b.fst][b.snd + 1] == '*'))
        cout << "NO\n";
    else if ((l.fst > 0 && s[l.fst - 1][l.snd] == '*') || (l.fst + 1 < h && s[l.fst + 1][l.snd] == '*'))
        cout << "NO\n";
    else if ((r.fst > 0 && s[r.fst - 1][r.snd] == '*') || (r.fst + 1 < h && s[r.fst + 1][r.snd] == '*'))
        cout << "NO\n";
    else
        cout << "YES\n";
}