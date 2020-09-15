#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
int main() {
    int num_cases;
    scanf("%d", &num_cases);
    
    while (num_cases--) {
        ll a, b; scanf("%lld %lld", &a, &b);
        
        ll num_ops = 0;
        while (a != 1 && b != 1) {
            if (a > b) {
                ll diff = a - b;
                ll subs = (diff / b) + 1;
                a -= (subs * b);
                num_ops += subs;
            } else {
                ll diff = b - a;
                ll subs = (diff / a) + 1;
                b -= (subs * a);
                num_ops += subs;
            }
        }
        
        num_ops += abs(a - b);
        printf("%lld\n", num_ops);
    }
}