#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
 
ll gcd(ll a, ll b, ll c) {
    return gcd(gcd(a, b), c);
}
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        
        bool coprime = gcd(a, b, c) == 1;
        if (!coprime) printf("NO\n");
        else {
            ll a_2 = a * a, b_2 = b * b, c_2 = c * c;
            ll greatest = max(a_2, max(b_2, c_2));
            ll sum = a_2 + b_2 + c_2;
            
            if (greatest * 2 == sum) printf("YES\n");
            else printf("NO\n");
        }
    }
}