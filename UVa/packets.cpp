#include <bits/stdc++.h>

using namespace std;

int main() {
    int A[10];
    while (true) {
        bool done = true;
        for (int i = 1; i <= 6; i++) {
            scanf("%d", &A[i]);
            done &= A[i] == 0;
        }

        if (done) break;

        int ans = A[6];

        ans += A[5];
        A[1] -= A[5] * 11;

        ans += A[4];
        A[2] -= A[4] * 5;

        ans += A[3] / 4;
        A[3] %= 4;

        if (A[3]) ans++;
        if (A[3] == 1) A[1] -= 7, A[2] -= 5;
        else if (A[3] == 2) A[1] -= 6, A[2] -= 3;
        else if (A[3] == 3) A[1] -= 5, A[2]--;

        if (A[2] > 0) {
            ans += A[2] / 9;
            A[2] %= 9;

            if (A[2]) ans++, A[1] -= 36 - (A[2] * 4);
        }
        else A[1] -= -A[2] * 4;

        if (A[1] > 0) ans += ceil(A[1] / 36.0);

        printf("%d\n", ans);
    }
}