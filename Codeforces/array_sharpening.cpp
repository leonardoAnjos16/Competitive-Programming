#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        int a[MAX];
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int l = 0, r = n - 1;
        bool possible = false;

        while (l <= r && !possible) {
            int k = (l + r) / 2;

            bool left = true;
            for (int i = 0; i <= k && left; i++)
                if (a[i] < i) left = false;

            bool right = true;
            for (int i = k; i < n && right; i++)
                if (a[i] < n - i - 1) right = false;

            if (left && right) possible = true;
            else if (!left) r = k - 1;
            else l = k + 1;
        }

        printf("%s\n", possible ? "Yes" : "No");
    }
}