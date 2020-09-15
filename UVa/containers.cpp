#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

int main() {
    char containers[MAX]; int case_num = 1;
    while (scanf("%s", containers), containers[0] != 'e') {
        int size = strlen(containers);

        vector< stack<char> > stacks(26);
        stacks[0].push(containers[0]);

        int num_stacks = 1;
        for (int i = 1; i < size; i++) {
            int aux = 0;
            while (aux < num_stacks && containers[i] > stacks[aux].top())
                aux++;

            stacks[aux].push(containers[i]);
            if (aux >= num_stacks) num_stacks++;
        }

        printf("Case %d: %d\n", case_num++, num_stacks);
    }
}