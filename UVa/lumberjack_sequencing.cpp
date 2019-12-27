#include <bits/stdc++.h>

using namespace std;

bool greater_than(int a, int b) {
    return a > b;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    printf("Lumberjacks:\n");
    for (int i = 0; i < num_cases; i++) {
        int beards[10], ordered[10];
        for (int j = 0; j < 10; j++) {
            scanf("%d", &beards[j]);
            ordered[j] = beards[j];
        }

        sort(ordered, ordered + 10);

        bool is_ordered = true;
        for (int j = 0; j < 10 && is_ordered; j++)
            if (ordered[j] != beards[j]) is_ordered = false;

        if (is_ordered) printf("Ordered\n");
        else {
            sort(ordered, ordered + 10, greater_than);

            is_ordered = true;
            for (int j = 0; j < 10 && is_ordered; j++)
                if (ordered[j] != beards[j]) is_ordered = false;

            if (is_ordered) printf("Ordered\n");
            else printf("Unordered\n");
        }
    }   
}