#include <bits/stdc++.h>

using namespace std;

#define MAX 15

typedef vector<int> vi;

int t, n, numbers[MAX];
set<vi> all_sols;
vi chosen;

void get_sums(int sum = 0, int counter = 0) {
    if (sum == t) {
        if (all_sols.find(chosen) != all_sols.end()) return;

        all_sols.insert(chosen);
        for (int i = 0; i < (int) chosen.size(); i++) {
            if (i > 0) printf("+");
            printf("%d", chosen[i]);
        }

        printf("\n");
    } else if (counter < n) {
        if (sum + numbers[counter] <= t) {
            chosen.push_back(numbers[counter]);
            get_sums(sum + numbers[counter], counter + 1);
            chosen.pop_back();
        }

        get_sums(sum, counter + 1);
    }
}

int main() {
    while (scanf("%d %d", &t, &n), n) {
        for (int i = 0; i < n; i++)
            scanf("%d", &numbers[i]);

        printf("Sums of %d:\n", t);
        get_sums();

        int num_sols = all_sols.size();
        if (!num_sols) printf("NONE\n");
        all_sols.clear(); chosen.clear();
    }
}