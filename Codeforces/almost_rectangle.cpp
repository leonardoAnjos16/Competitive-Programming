#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 405;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        string cells[MAX];
        vector<pii> marked;

        for (int i = 0; i < n; i++) {
            cin >> cells[i];
            for (int j = 0; j < n; j++)
                if (cells[i][j] == '*')
                    marked.pb({ i, j });
        }

        if (marked[0].fst == marked[1].fst) {
            int row = marked[0].fst + (!marked[0].fst ? 1 : -1);
            marked.pb({ row, marked[0].snd });
            marked.pb({ row, marked[1].snd });
        } else if (marked[0].snd == marked[1].snd) {
            int col = marked[0].snd + (!marked[0].snd ? 1 : -1);
            marked.pb({ marked[0].fst, col });
            marked.pb({ marked[1].fst, col });
        } else {
            marked.pb({ marked[0].fst, marked[1].snd });
            marked.pb({ marked[1].fst, marked[0].snd });
        }

        for (auto cell: marked)
            cells[cell.fst][cell.snd] = '*';

        for (int i = 0; i < n; i++)
            cout << cells[i] << "\n";
    }
}