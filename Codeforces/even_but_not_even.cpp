#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);

        string ans = "";
        while (n--) {
            int d; scanf("%1d", &d);
            if (d % 2) ans += (d + '0');
        }

        int size = ans.size();
        if (size < 2) printf("-1\n");
        else if (size % 2) printf("%s\n", ans.substr(1).c_str());
        else printf("%s\n", ans.c_str());
    }
}