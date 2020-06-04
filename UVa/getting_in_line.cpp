#include <bits/stdc++.h>

using namespace std;

#define coord pair<int, int>
#define x first
#define y second

const int MAX = 10;

double dist(coord a, coord b) {
    int dist_x = a.x - b.x, dist_y = a.y - b.y;
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

int main() {
    int n, case_num = 1;
    while (scanf("%d", &n), n) {
        coord A[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d %d", &A[i].x, &A[i].y);

        sort(A, A + n);

        coord ans[MAX];
        double cable = DBL_MAX;

        do {
            double sum = 0.0;
            for (int i = 1; i < n; i++)
                sum += dist(A[i - 1], A[i]);

            if (sum < cable) {
                cable = sum;
                copy(A, A + n, ans);
            }
        } while (next_permutation(A, A + n));

        printf("**********************************************************\n");
        printf("Network #%d\n", case_num++);

        for (int i = 1; i < n; i++)
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", ans[i - 1].x, ans[i - 1].y, ans[i].x, ans[i].y, dist(ans[i - 1], ans[i]) + 16.0);

        printf("Number of feet of cable required is %.2lf.\n", cable + 16.0 * (n - 1));
    }
}