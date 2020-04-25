#include <bits/stdc++.h>
 
using namespace std;
 
#define long long long int
#define x first
#define y second
 
long pow(long a, long b, long m) {
    if (b == 0) return 1;
    else if (b % 2) return (a * pow((a * a) % m, (b - 1) / 2, m)) % m;
    else return pow((a * a) % m, b / 2, m);
}
 
pair<long, long> get_coefs(long a, long m) {
    if (m == 0) return {1L, 0L};
    else {
        pair<long, long> coefs = get_coefs(m, a % m);
        return {coefs.y, coefs.x - (a / m) * coefs.y};
    }
}
 
int main() {
    long A, B, C, M;
    scanf("%lld %lld %lld %lld", &A, &B, &C, &M);
 
    long mod_inverse = (get_coefs(C, M).x + M) % M;
    long ans = (pow(A % M, B, M) * mod_inverse) % M;
 
    printf("%lld\n", ans);
}