#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> numbers;
    int number;
    while (scanf("%u", &number) != EOF) {
        numbers.push_back(number);

        int middle = numbers.size() / 2;
        nth_element(numbers.begin(), numbers.begin() + middle, numbers.end());

        if (numbers.size() % 2) printf("%d\n", numbers[middle]);
        else {
            double median = numbers[middle--] / 2.0;
            nth_element(numbers.begin(), numbers.begin() + middle, numbers.end());
            median += numbers[middle] / 2.0;
            printf("%d\n", (int) median);
        }
    }
}