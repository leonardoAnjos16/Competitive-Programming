#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, b; scanf("%d %d", &m, &b);
    long long int max_bananas = INT_MIN;

    long long int height = b, width = 0;
    while (height >= 0) {
        long long int bananas = (height * (height + 1)) / 2;
        bananas *= (width + 1);
        bananas += (height + 1) * ((width * (width + 1)) / 2);

        max_bananas = max(max_bananas, bananas);
        height--; width += m;
    }

    printf("%lld\n", max_bananas);
}