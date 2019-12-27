#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int size;
        long long num_moves;
        scanf("%d %lld", &size, &num_moves);

        string digits;
        cin >> digits;

        int first_one = 0;
        while (first_one < size && digits[first_one] != '1') first_one++;
        int first_zero = first_one;

        bool done = false;
        while (num_moves > 0 && !done) {
            first_zero++;
            while (first_zero < size && digits[first_zero] != '0') first_zero++;

            if (first_zero >= size) done = true;
            else {
                int moves = first_zero - first_one;
                if (moves > num_moves) moves = num_moves;

                digits[first_zero] = '1';
                digits[first_zero - moves] = '0';

                num_moves -= moves;
                first_one++;
            }
        }

        cout << digits << endl;
    }
}