#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;

char all[10][8] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};

int N, burned[7];
char numbers[MAX][8];
bool countdown;

void get_countdown(int index = 0, int last = 0) {
    if (index >= N) countdown = true;
    else if (!countdown) {
        if (index) {
            for (int i = 0; i < 7; i++)
                if (burned[i] && numbers[index][i] == 'Y') return;

            bool possible = true;
            for (int i = 0; i < 7; i++)
                if (all[last - 1][i] < numbers[index][i])
                    possible = false;

            if (possible) {
                for (int j = 0; j < 7; j++)
                    if (numbers[index][j] != all[last - 1][j])
                        burned[j]++;

                get_countdown(index + 1, last - 1);

                for (int j = 0; j < 7; j++)
                    if (numbers[index][j] != all[last - 1][j])
                        burned[j]--;
            }
        } else {
            for (int i = 9; i >= N - 1; i--) {
                bool possible = true;
                for (int j = 0; j < 7; j++)
                    if (all[i][j] < numbers[0][j])
                        possible = false;

                if (possible) {
                    for (int j = 0; j < 7; j++)
                        if (numbers[index][j] != all[i][j])
                            burned[j]++;

                    get_countdown(index + 1, i);

                    for (int j = 0; j < 7; j++)
                        if (numbers[index][j] != all[i][j])
                            burned[j]--;
                }
            }
        }
    }
}

int main() {
    while (scanf("%d", &N), N) {
        for (int i = 0; i < N; i++)
            scanf("%s", numbers[i]);

        countdown = false;
        for (int i = 0; i < 7; i++)
            burned[i] = 0;

        get_countdown();
        printf("%s\n", countdown ? "MATCH" : "MISMATCH");
    }
}