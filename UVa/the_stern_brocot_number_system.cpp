#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n != 1 || m != 1) {
        int l[2] = {0, 1};
        int r[2] = {1, 0};

        string number = "";
        while (true) {
            int mid[2] = {l[0] + r[0], l[1] + r[1]};
            if (mid[0] == n && mid[1] == m) break;
            else if ((m * mid[0]) < (n * mid[1])) l[0] = mid[0], l[1] = mid[1], number += 'R';
            else r[0] = mid[0], r[1] = mid[1], number += 'L';
        }

        printf("%s\n", number.c_str());
    }
}