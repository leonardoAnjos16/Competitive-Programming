#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > factorizations;

void get_factorizations(int number, vector<int> factors, int last_divisor = 2) {
    int square_root = (int) sqrt(number);
    for (int i = last_divisor; i <= square_root; i++) {
        if (number % i == 0) {
            factors.push_back(i);
            get_factorizations(number / i, factors, i);
            factors.pop_back();
        }
    }

    factors.push_back(number);
    factorizations.push_back(factors);
}

int main() {
    int number;
    while (scanf("%d", &number), number) {
        vector<int> factors;
        get_factorizations(number, factors);
        factorizations.pop_back();

        int size = factorizations.size();
        printf("%d\n", size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < factorizations[i].size(); j++) {
                if (j > 0) printf(" ");
                printf("%d", factorizations[i][j]);
            }

            printf("\n");
        }

        factorizations.clear();
    }    
}