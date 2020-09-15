#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q, case_num = 1;
    while (scanf("%d %d", &N, &Q), N || Q) {
        vector<int> numbers(N);
        for (int i = 0; i < N; i++)
            scanf("%d", &numbers[i]);

        sort(numbers.begin(), numbers.end());

        printf("CASE# %d:\n", case_num++);
        while (Q--) {
            int x; scanf("%d", &x);
            int index = lower_bound(numbers.begin(), numbers.end(), x) - numbers.begin();

            if (index == N || numbers[index] > x) printf("%d not found\n", x);
            else printf("%d found at %d\n", x, index + 1);
        }
    }
}