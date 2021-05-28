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

const int MAX = 405;

int n, d[MAX];

void get_pos(int ta[MAX], int tb[MAX], vector<bitset<MAX>> &ans) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int start_a[MAX];
            start_a[i] = 0;

            for (int k = 1; k < n; k++)
                start_a[(i + k) % n] = start_a[(i + k - 1 + n) % n] + ta[(i + k - 1 + n) % n] + d[(i + k - 1 + n) % n];

            int start_b[MAX];
            start_b[j] = 0;

            for (int k = 1; k < n; k++)
                start_b[(j + k) % n] = start_b[(j + k - 1 + n) % n] + tb[(j + k - 1 + n) % n] + d[(j + k - 1 + n) % n];

            ans[i][j] = true;
            for (int k = 0; k < n && ans[i][j]; k++) {
                if (!(start_a[k] >= start_b[k] + tb[k] || start_a[k] + ta[k] <= start_b[k]))
                    ans[i][j] = false;

                if (!(start_b[k] >= start_a[k] + ta[k] || start_b[k] + tb[k] <= start_a[k]))
                    ans[i][j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i];

    int tt[MAX];
    for (int i = 0; i < n; i++)
        cin >> tt[i];

    int ta[MAX];
    for (int i = 0; i < n; i++)
        cin >> ta[i];

    int ti[MAX];
    for (int i = 0; i < n; i++)
        cin >> ti[i];

    vector<bitset<MAX>> pos_ta(n);
    get_pos(tt, ta, pos_ta);

    vector<bitset<MAX>> pos_ti(n);
    get_pos(tt, ti, pos_ti);

    vector<bitset<MAX>> pos_ai(n);
    get_pos(ta, ti, pos_ai);

    int x, y, z;
    bool possible = false;

    for (int i = 0; i < n && !possible; i++)
        for (int j = 0; j < n && !possible; j++)
            for (int k = 0; k < n && !possible; k++)
                if (pos_ta[i][j] && pos_ti[i][k] && pos_ai[j][k])
                    possible = true, x = i + 1, y = j + 1, z = k + 1;

    if (!possible) cout << "impossible\n";
    else cout << x << " " << y << " " << z << "\n";
}