#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

typedef pair<int, int> int_pair;

int main() {
    int num_soldiers, num_killed;
    while (true) {
        scanf("%d %d", &num_soldiers, &num_killed);
        if (!num_soldiers && !num_killed) return 0;

        int_pair buddies[MAX];
        buddies[0] = {-1, 1};
        buddies[num_soldiers - 1] = {num_soldiers - 2, -1};

        for (int i = 1; i < num_soldiers - 1; i++)
            buddies[i] = {i - 1, i + 1};

        for (int i = 0; i < num_killed; i++) {
            int left, right;
            scanf("%d %d", &left, &right);

            buddies[buddies[left - 1].first].second = buddies[right - 1].second;
            buddies[buddies[right - 1].second].first = buddies[left - 1].first;

            if (buddies[left - 1].first == -1) printf("* ");
            else printf("%d ", buddies[left - 1].first + 1);

            if (buddies[right - 1].second == -1) printf("*\n");
            else printf("%d\n", buddies[right - 1].second);
        }

        printf("-\n");
    }
}