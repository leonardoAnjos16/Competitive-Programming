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

string board;
set<string> reachable;
set<string> done;

bool win_or_draw() {
    string aux[3];
    for (int i = 0; i < 3; i++)
        aux[i] = board.substr(3 * i, 3);

    for (int i = 0; i < 3; i++) {
        int cnt[2][2] = {0};
        for (int j = 0; j < 3; j++) {
            if (aux[i][j] != '_')
                cnt[0][aux[i][j] == 'O']++;

            if (aux[j][i] != '_')
                cnt[1][aux[j][i] == 'O']++;
        }

        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                if (cnt[j][k] == 3) return true;
    }

    if (aux[0][0] != '_' && aux[0][0] == aux[1][1] && aux[1][1] == aux[2][2])
        return true;

    if (aux[0][2] != '_' && aux[0][2] == aux[1][1] && aux[1][1] == aux[2][0])
        return true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (aux[i][j] == '_')
                return false;

    return true;
}

void get_reachable(char turn = 'X') {
    if (reachable.count(board)) return;
    reachable.insert(board);

    if (win_or_draw()) done.insert(board);
    else {
        for (int i = 0; i < 9; i++)
            if (board[i] == '_') {
                board[i] = turn;
                get_reachable(turn == 'X' ? 'O' : 'X');
                board[i] = '_';
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    board.assign(9, '_');
    get_reachable();

    while (T--) {
        board = "";
        for (int i = 0; i < 3; i++) {
            string aux; cin >> aux;
            board += aux;
        }

        if (!reachable.count(board)) cout << "3\n";
        else if (!done.count(board)) cout << "2\n";
        else cout << "1\n";
    }
}