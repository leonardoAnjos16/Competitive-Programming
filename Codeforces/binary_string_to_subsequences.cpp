#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        char s[MAX]; scanf("%s", s);

        stack<int> endings[2];
        int ans = 0, seq[MAX];

        for (int i = 0; i < n; i++) {
            int dig = s[i] - '0';
            if (endings[(dig + 1) % 2].empty()) {
                seq[i] = ++ans;
                endings[dig].push(ans);
            } else {
                seq[i] = endings[(dig + 1) % 2].top();
                endings[(dig + 1) % 2].pop();
                endings[dig].push(seq[i]);
            }
        }

        printf("%d\n", ans);
        for (int i = 0; i < n; i++) {
            if (i) printf(" ");
            printf("%d", seq[i]);
        }

        printf("\n");
    }
}