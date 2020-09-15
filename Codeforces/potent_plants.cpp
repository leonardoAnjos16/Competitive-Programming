#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int w; char plants[MAX];
        scanf("%d %s", &w, plants);

        int sum = 0, size = strlen(plants);
        for (int i = 0; i < size && sum <= w; i++)
            sum += plants[i] - 'A' + 1;

        if (sum <= w) printf("YES\n");
        else printf("NO\n");
    }
}