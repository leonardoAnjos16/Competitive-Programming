#include <bits/stdc++.h>

using namespace std;

void reverse(int &n) {
    int ans = 0;
    while (n) {
        ans *= 10;
        ans += n % 10;
        n /= 10;
    }

    n = ans;
}

int main() {
    int N; scanf("%d", &N);
    while (N--) {
        int a, b; scanf("%d %d", &a, &b);
        reverse(a); reverse(b);

        int ans = a + b;
        reverse(ans);

        printf("%d\n", ans);
    }
}