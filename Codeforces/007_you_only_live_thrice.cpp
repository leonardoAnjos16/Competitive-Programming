#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll m; scanf("%lld", &m);

        bool okay = false;
        if (m % 3 == 0) printf("AGENT 003\n"), okay = true;
        if (m % 5 == 0) printf("AGENT 005\n"), okay = true;
        if (m % 7 == 0) printf("AGENT 007\n"), okay = true;

        if (!okay) printf("NONE\n");
        printf("---\n");
    }
}