#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        char s[MAX]; scanf("%s", s);

        int idx = 0;
        while (idx < n && s[idx] != '8') idx++;

        bool possible = n - idx >= 11;
        printf("%s\n", possible ? "YES" : "NO");
    }
}