#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int num_rows, num_cols;
    while (scanf("%d %d", &num_rows, &num_cols) != EOF) {
        vector<vii> transposed_matrix(num_cols);
        for (int i = 0; i < num_rows; i++) {
            int num_non_zero;
            scanf("%d", &num_non_zero);

            vector<int> indices;
            int index;

            for (int j = 0; j < num_non_zero; j++)
                scanf("%d", &index), indices.push_back(index);

            int value;
            for (int j = 0; j < num_non_zero; j++)
                scanf("%d", &value), transposed_matrix[indices[j] - 1].push_back({i + 1, value});
        }

        printf("%d %d\n", num_cols, num_rows);
        for (int i = 0; i < num_cols; i++) {
            int size = transposed_matrix[i].size();
            printf("%d", size);

            for (int j = 0; j < size; j++)
                printf(" %d", transposed_matrix[i][j].first);

            printf("\n");
            for (int j = 0; j < size; j++) {
                if (j > 0) printf(" ");
                printf("%d", transposed_matrix[i][j].second);
            }

            printf("\n");
        }
    }
}