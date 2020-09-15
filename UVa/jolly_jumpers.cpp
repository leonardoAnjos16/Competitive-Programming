#include <bits/stdc++.h>

using namespace std;

#define MAX 3001

bool is_jolly(int numbers[], int size) {
    vector<bool> used(size - 1, false);
    for (int i = 1; i < size; i++) {
        int diff = abs(numbers[i] - numbers[i - 1]);
        if (diff == 0 || diff >= size || used[diff - 1]) return false;
        used[diff - 1] = true;
    }

    return true;
}

int main() {
    int size;
    while (scanf("%d", &size) != EOF) {
        int numbers[MAX];
        for (int i = 0; i < size; i++)
            scanf("%d", &numbers[i]);

        if (is_jolly(numbers, size)) printf("Jolly\n");
        else printf("Not jolly\n");
    }
}