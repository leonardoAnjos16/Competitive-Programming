#include <bits/stdc++.h>

using namespace std;

const int size = 6;

int main() {
    int numbers[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            cin >> numbers[i][j];

    int max = -100;
    for (int i = 0; i < size - 2; i++) {
        for (int j = 0; j < size - 2; j++) {
            int sum = numbers[i][j] + numbers[i][j + 1] + numbers[i][j + 2];
            sum += numbers[i + 1][j + 1];
            sum += numbers[i + 2][j] + numbers[i + 2][j + 1] + numbers[i + 2][j + 2];

            if (sum > max) max = sum;
        }
    }

    cout << max << endl;
    return 0;
}