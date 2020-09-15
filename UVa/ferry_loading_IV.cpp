#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int l, m; scanf("%d %d", &l, &m);
        l *= 100;

        queue<int> left, right;
        while (m--) {
            int length; char side[10];
            scanf("%d %s", &length, side);

            if (!strcmp(side, "left")) left.push(length);
            else right.push(length);
        }

        int side = 0, num_trips = 0;
        while (!left.empty() || !right.empty()) {
            int length = 0;
            if (side == 0) {
                while (!left.empty() && length + left.front() <= l)
                    length += left.front(), left.pop();
            } else {
                while (!right.empty() && length + right.front() <= l)
                    length += right.front(), right.pop();
            }

            num_trips++;
            side = ++side % 2;
        }

        printf("%d\n", num_trips);
    }
}