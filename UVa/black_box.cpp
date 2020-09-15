#include <bits/stdc++.h>

using namespace std;

#define MAX 30001

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_adds, num_gets;
        scanf("%d", &num_adds);
        scanf("%d", &num_gets);

        int adds[MAX];
        for (int i = 0; i < num_adds; i++)
            scanf("%d", &adds[i]);

        int gets[MAX];
        for (int i = 0; i < num_gets; i++)
            scanf("%d", &gets[i]);

        multiset<int> numbers;
        int get_index = 0, add_index = 0;

        numbers.insert(adds[add_index++]);
        multiset<int>::iterator it = numbers.begin();

        while (get_index < num_gets) {
            while (numbers.size() < gets[get_index]) {
                numbers.insert(adds[add_index]);
                if (it == numbers.end() || adds[add_index] < *it) it--;
                add_index++;
            }

            printf("%d\n", *it);
            get_index++; it++;
        }

        if (num_cases > 0) printf("\n");
    }
}