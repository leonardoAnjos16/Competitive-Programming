#include <bits/stdc++.h>

using namespace std;

void print(int array[], int size) {
    printf("%d", array[0]);
    for (int i = 1; i < size; i++)
        printf(" %d", array[i]);

    printf("\n");
}

bool is_prime(int number) {
    for (int i = 2; i < number; i++)
        if (number % i == 0) return false;

    return true;
}

void solve(int circle[], bool used[], int size, int index = 1) {
    if (index < size) {
        for (int i = 2; i <= size; i++) {
            if (!used[i - 1] && is_prime(circle[index - 1] + i)) {
                circle[index] = i;
                used[i - 1] = true;
                solve(circle, used, size, index + 1);
                used[i - 1] = false;
            }
        }
    } else if (is_prime(circle[index - 1] + 1)) print(circle, size);
}

int main() {
    int size, counter = 1;
    while (cin >> size) {
        if (counter > 1) printf("\n");
        
        int circle[16];
        bool used[16];

        circle[0] = 1;
        used[0] = true;

        for (int i = 1; i < size; i++)
            used[i] = false;

        printf("Case %d:\n", counter++);
        solve(circle, used, size);
    }
}