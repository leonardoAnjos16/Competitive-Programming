#include <iostream>
 
using namespace std;
 
int main() {
    long long int n; cin >> n;
    
    while (n > 1LL) {
        cout << n << " ";
        if (!(n & 1LL)) n >>= 1LL;
        else n *= 3LL, n++;
    }
    
    cout << "1\n";
}