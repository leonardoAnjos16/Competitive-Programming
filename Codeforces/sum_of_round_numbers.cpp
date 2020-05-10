#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int mult = 1;
        vector<int> round;

        while (n) {
            if (n % 10) round.push_back((n % 10) * mult);
            n /= 10; mult *= 10;
        }

        int ans = round.size();
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++)
            printf("%d ", round[i]);

        printf("\n");
    }
}