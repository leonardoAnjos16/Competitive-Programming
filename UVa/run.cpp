#include <bits/stdc++.h>

using namespace std;

#define MAX 10

vector<int> runaround_numbers;

bool is_runaround(int number) {
    char digits[MAX]; sprintf(digits, "%d", number);
    int num_digits = strlen(digits);

    int pos = 0, used = 0;
    for (int i = 0; i < num_digits; i++) {
        int digit = digits[pos] - '0';
        if (digit == 0 || used & (1 << digit)) return false;

        used |= (1 << digit);
        pos = (pos + digit) % num_digits;
    }

    if (pos) return false;
    for (int i = 0; i < num_digits; i++) {
        int digit = digits[i] - '0';
        if (!(used & (1 << digit))) return false;
    }

    return true;
}

void get_numbers() {
    for (int i = 1; i <= 9876543; i++)
        if (is_runaround(i))
            runaround_numbers.push_back(i);
}

int main() {
    int number, case_num = 1;
    get_numbers();

    while (scanf("%d", &number), number) {
        int runaround = *lower_bound(runaround_numbers.begin(), runaround_numbers.end(), number);
        printf("Case %d: %d\n", case_num++, runaround);
    }
}