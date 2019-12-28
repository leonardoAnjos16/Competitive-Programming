#include <bits/stdc++.h>

using namespace std;

#define NUM_SCHOOLS 4

int main() {
    int num_queries;
    scanf("%d", &num_queries);

    int order[NUM_SCHOOLS], counter = 0;
    for (int i = 0; i < NUM_SCHOOLS; i++)
        order[i] = -1;

    queue<int> queues[NUM_SCHOOLS];
    while (num_queries--) {
        char operation;
        scanf("\n%c", &operation);

        if (operation == 'E') {
            int school, roll_num;
            scanf("%d %d", &school, &roll_num);

            if (order[school - 1] == -1) order[school - 1] = counter++;
            queues[school - 1].push(roll_num);
        } else {
            int min = -1;
            for (int i = 0; i < NUM_SCHOOLS; i++) {
                if (order[i] != -1 && (min == -1 || order[i] < order[min]))
                    min = i;
            }

            printf("%d %d\n", (min + 1), queues[min].front());
            queues[min].pop();

            if (queues[min].empty())
                order[min] = -1;
        }
    }
}