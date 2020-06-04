#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> unique;
    for (int i = 0; i < 4; i++) {
        int s; scanf("%d", &s);
        unique.insert(s);
    }

    int ans = 4 - (int) unique.size();
    printf("%d\n", ans);
}