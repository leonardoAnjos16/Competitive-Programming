#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vector<vi> sols; vi rows(8);
bitset<20> rw, ld, rd;

void get_sols(int col = 0) {
    if (col >= 8) sols.push_back(rows);
    else {
        for (int i = 0; i < 8; i++) {
            if (!rw[i] && !ld[i - col + 7] && !rd[i + col]) {
                rw[i] = ld[i - col + 7] = rd[i + col] = true;
                rows[col] = i + 1; get_sols(col + 1);
                rw[i] = ld[i - col + 7] = rd[i + col] = false;
            }
        }
    }
}

int main() {
    get_sols();
    int size = sols.size(), case_num = 1;

    vi start(8);
    while (scanf("%d", &start[0]) != EOF) {
        for (int i = 1; i < 8; i++)
            scanf("%d", &start[i]);

        int min_movs = INT_MAX;
        for (int i = 0; i < size; i++) {
            int num_movs = 0;
            for (int j = 0; j < 8; j++)
                if (start[j] != sols[i][j])
                    num_movs++;

            min_movs = min(min_movs, num_movs);
        }

        printf("Case %d: %d\n", case_num++, min_movs);
    }
}