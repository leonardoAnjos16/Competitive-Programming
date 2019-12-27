#include <bits/stdc++.h>

using namespace std;

long long int sum(long long int number) {
    return (number * (number + 1)) / 2;
}

int main() {
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++) {
        long long int number, div, result;
        cin >> number;
        number--;

        div = number / 3;
        result = 3 * sum(div);

        div = number / 5;
        result += 5 * sum(div);

        div = number / 15;
        result -= 15 * sum(div);

        cout << result << endl;
    }

    return 0;
}