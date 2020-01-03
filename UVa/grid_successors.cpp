#include <bits/stdc++.h>

using namespace std;

bool all_zero(int matrix[][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i][j]) return false;

    return true;
}

void f(int matrix[][3]) {
    int new_matrix[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = j > 0 ? matrix[i][j - 1] + (j < 2 ? matrix[i][j + 1] : 0) : matrix[i][j + 1];
            sum += i > 0 ? matrix[i - 1][j] + (i < 2 ? matrix[i + 1][j] : 0) : matrix[i + 1][j];
            new_matrix[i][j] = sum % 2;
        }
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = new_matrix[i][j];
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int matrix[3][3];
        for (int j = 0; j < 3; j++)
            scanf("%1d%1d%1d", &matrix[j][0], &matrix[j][1], &matrix[j][2]);

        int counter = 0;
        while (!all_zero(matrix))
            f(matrix), counter++;

        printf("%d\n", (counter - 1));
    }
}