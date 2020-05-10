#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n[3];
        for (int i = 0; i < 3; i++)
            scanf("%d", &n[i]);

        string ans = "";
        if (!n[1]) {
            int size = (n[0] > 0) ? n[0] : n[2];
            char bit = (n[0] > 0) ? '0' : '1';

            for (int i = 0; i <= size; i++) ans += bit;
        } else {
            for (int i = 0; i <= n[0]; i++) ans += '0';
            for (int i = 0; i < n[2]; i++) ans += '1';
            for (int i = 1; i <= n[1]; i++) ans += i % 2 + '0';
        }

        printf("%s\n", ans.c_str());
    }
}