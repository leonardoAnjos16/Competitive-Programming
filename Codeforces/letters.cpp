#include <bits/stdc++.h>

using namespace std;

#define long long long int

const int MAX = 2e5 + 5;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    long rooms[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &rooms[i]);
        rooms[i] += rooms[i - 1];
    }

    while (m--) {
        long b; scanf("%lld", &b);

        int dorm = lower_bound(rooms, rooms + n + 1, b) - rooms;
        long room = b - rooms[dorm - 1];

        printf("%d %lld\n", dorm, room);
    }
}