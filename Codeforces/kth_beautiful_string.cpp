#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);

        string ans(n, 'a');

        int l = n - 2;
        while (k > n - l - 1)
            k -= n - l - 1, l--;

        ans[l] = ans[n - k] = 'b';
        printf("%s\n", ans.c_str());
    }
}