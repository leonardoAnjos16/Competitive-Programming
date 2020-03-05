#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

int n, m, pieces[MAX][2];
bool possible = false;
bitset<MAX> used;

void get_possible(int last_used, int last, int index = 0) {
    if (index >= n && last_used == last) possible = true;
    else if (index < n) {
        for (int i = 0; i < m && !possible; i++) {
            if (!used[i]) {
                used[i] = true;
                if (pieces[i][0] == last_used) get_possible(pieces[i][1], last, index + 1);
                else if (pieces[i][1] == last_used) get_possible(pieces[i][0], last, index + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    while (scanf("%d", &n), n) {
        scanf("%d", &m);

        int first, last;
        scanf("%*d %d", &first);
        scanf("%d %*d", &last);

        for (int i = 0; i < m; i++)
            scanf("%d %d", &pieces[i][0], &pieces[i][1]);

        get_possible(first, last);
        printf("%s\n", possible ? "YES" : "NO");
        possible = false; used.reset();
    }
}