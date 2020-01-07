#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

vector<int> some_primatic;

bool is_prime(int number) {
    double square_root = sqrt(number);
    for (int i = 2; i <= square_root; i++)
        if (number % i == 0) return false;
        
    return true;
}

bool is_primatic(int number) {
    if (is_prime(number) || binary_search(some_primatic.begin(), some_primatic.end(), number)) return true;
    else return false;
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    int prime = 2;
    while (pow(prime, prime) < MAX) {
        some_primatic.push_back(pow(prime, prime));
        while (!is_prime(++prime));
    }
    
    int min_primatic[MAX] = { 0 };
    while (num_cases--) {
        int number;
        scanf("%d", &number);
        
        for (int i = 2; i <= number; i++) {
            if (!min_primatic[i]) {
                if (is_primatic(i)) min_primatic[i] = 1;
                else {
                    int minimum = INT_MAX;
                    for (int j = 2; j <= i / 2; j++)
                        minimum = min(minimum, min_primatic[j] + min_primatic[i - j]);
                        
                    min_primatic[i] = minimum;
                }
            }
        }
        
        printf("%d\n", min_primatic[number]);
    }
}