#include <bits/stdc++.h>

using namespace std;

#define lb(A, x) lower_bound(A.begin(), A.end(), x)
#define ub(A, x) upper_bound(A.begin(), A.end(), x)

int main() {
    int N; scanf("%d", &N);

    vector<int> heights(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &heights[i]);

    int Q; scanf("%d", &Q);
    while (Q--) {
        int height; scanf("%d", &height);

        int last_shorter = lb(heights, height) - heights.begin() - 1;
        int first_taller = ub(heights, height) - heights.begin();

        if (last_shorter >= 0) printf("%d ", heights[last_shorter]);
        else printf("X ");

        if (first_taller < N) printf("%d\n", heights[first_taller]);
        else printf("X\n");
    }
}