#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int s, i, e; scanf("%d %d %d", &s, &i, &e);

        int min_sum = ceil((i + e - s + 1) / 2.0);
        min_sum = max(min_sum, 0);

        int diff_chars = e - min_sum + 1;
        diff_chars = max(diff_chars, 0);
        
        printf("%d\n", diff_chars);
    }
}