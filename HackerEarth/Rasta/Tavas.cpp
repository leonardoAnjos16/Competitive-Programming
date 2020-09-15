#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> primes;
 
bool is_prime(int number) {
    double square_root = sqrt(number);
    for (int i = 2; i <= square_root; i++)
        if (number % i == 0) return false;
        
    return true;
}
 
void get_primes(int limit) {
    for (int i = 2; i <= limit; i++)
        if (is_prime(i)) primes.push_back(i);
}
 
int main() {
    int n, k; scanf("%d %d", &n, &k);
    get_primes(n);
    
    vector<int> sums(n + 1);
    for (int i = 0; i < primes.size(); i++) {
        int number = primes[i];
        while (number <= n) {
            sums[number] += primes[i];
            number += primes[i];
        }
    }
    
    int num_tavases = 0;
    for (int i = 1; i <= n; i++)
        if (sums[i] == k) num_tavases++;
        
    printf("%d\n", num_tavases);
}