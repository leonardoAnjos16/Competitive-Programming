#include <bits/stdc++.h>

using namespace std;

const int MAX = 5e4 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        char num[MAX]; scanf("%s", num);

        char a[MAX], b[MAX];
        a[0] = b[0] = '1';
        a[n] = b[n] = '\0';

        bool equal = true;
        for (int i = 1; i < n; i++) {
            if (num[i] == '0') a[i] = b[i] = '0';
            else if (num[i] == '1') {
                if (equal) a[i] = '1', b[i] = '0';
                else a[i] = '0', b[i] = '1';
                
                equal = false;
            } else {
                if (equal) a[i] = b[i] = '1';
                else a[i] = '0', b[i] = '2';
            }
        }

        printf("%s\n%s\n", a, b);
    }
}