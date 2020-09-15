#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main() {
    vector<int> scores;
    for (int i = 0; i <= 60; i++) {
        if (i == 50 || i < 20 || (!(i % 2) && i / 2 <= 20) || (!(i % 3) && i / 3 <= 20))
            scores.push_back(i);
    }

    char delim[100];
    for (int i = 0; i < 70; i++)
        delim[i] = '*';

    delim[70] = '\0';

    int score;
    while (scanf("%d", &score), score > 0) {
        int num_combs = 0, num_perms = 0;
        for (int i = 0; i < (int) scores.size() && scores[i] <= score; i++) {
            int after_first = score - scores[i];
            for (int j = i; j < (int) scores.size() && scores[j] <= after_first; j++) {
                int after_second = after_first - scores[j];
                for (int k = j; k < (int) scores.size() && scores[k] <= after_second; k++) {
                    if (scores[k] == after_second) {
                        num_combs++;
                        if (i == j && j == k) num_perms++;
                        else if (i == j || j == k || i == k) num_perms += 3;
                        else num_perms += 6;
                    }
                }
            }
        }

        if (!num_combs) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, num_combs);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, num_perms);
        }

        printf("%s\n", delim);
    }

    printf("END OF OUTPUT\n");
}