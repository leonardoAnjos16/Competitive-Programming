#include <bits/stdc++.h>

using namespace std;

int numbers[5];

bool is_possible(int result, int counter = 1) {
    if (counter == 5 && result == 23) return true;
    else if (counter == 5) return false;

    int sum = result + numbers[counter], sub = result - numbers[counter], prod = result * numbers[counter];
    return is_possible(sum, counter + 1) || is_possible(sub, counter + 1) || is_possible(prod, counter + 1);
}

int main() {
    while (true) {
        int num_zero = 0;
        for (int i = 0; i < 5; i++) {
            scanf("%d", &numbers[i]);
            if (!numbers[i]) num_zero++;
        }

        if (num_zero == 5) break;

        sort(numbers, numbers + 5);
        bool possible = false;

        do {
            if (is_possible(numbers[0])) possible = true;
        } while (!possible && next_permutation(numbers, numbers + 5));

        printf("%s\n", possible ? "Possible" : "Impossible");
    }
}