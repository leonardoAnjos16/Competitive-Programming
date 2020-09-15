#include <bits/stdc++.h>

using namespace std;

int main() {
    int number;
    map<int, int> frequencies;
    vector<int> unique_numbers;

    while (scanf("%d", &number) != EOF) {
        if (frequencies.find(number) != frequencies.end()) frequencies[number]++;
        else {
            frequencies[number] = 1;
            unique_numbers.push_back(number);
        }
    }

    for (auto n: unique_numbers)
        printf("%d %d\n", n, frequencies[n]);
}