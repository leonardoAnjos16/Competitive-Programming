#include <bits/stdc++.h>

using namespace std;

int sum_digits(int number) {
    long long pow = 1;
    int sum = 0;
    while (number >= pow) {
        pow *= 10;

        int remainder = number % pow;
        number -= remainder;

        int digit = remainder / (pow / 10);
        sum += digit;
    }

    return sum;
}

int g(int number) {
    if (number < 10) return number;
    else return g(sum_digits(number));
}

int main() {
    int number;
    scanf("%d", &number);

    while (number != 0) {
        printf("%d\n", g(number));
        scanf("%d", &number);
    }
}