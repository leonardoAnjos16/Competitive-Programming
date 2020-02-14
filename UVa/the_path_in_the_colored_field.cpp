#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    while (scanf("%d", &size) != EOF) {
        vector<string> matrix(size);
        for (int i = 0; i < size; i++)
            cin >> matrix[i];

        int max_dist = INT_MIN;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == '1') {
                    int min_dist = INT_MAX;
                    for (int k = 0; k < size; k++) {
                        for (int l = 0; l < size; l++) {
                            if (matrix[k][l] == '3') {
                                int dist = abs(k - i) + abs(l - j);
                                min_dist = min(min_dist, dist);
                            }
                        }
                    }

                    max_dist = max(max_dist, min_dist);
                }
            }
        }

        printf("%d\n", max_dist);
    }
}