#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_students;
        scanf("%d", &num_students);

        int score; scanf("%d", &score);
        int max_score = score, max_diff = INT_MIN;

        for (int i = 1; i < num_students; i++) {
            scanf("%d", &score);
            max_diff = max(max_diff, max_score - score);
            max_score = max(max_score, score);
        }

        printf("%d\n", max_diff);
    }
}