#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e3 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int pos[MAX] = {0};
        bool palindrome = false;

        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (pos[a] && (i - pos[a]) > 0) palindrome = true;
            if (!pos[a]) pos[a] = i + 1;
        }

        if (palindrome) printf("YES\n");
        else printf("NO\n");
    }
}