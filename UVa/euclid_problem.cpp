#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 2e5 + 5;

long X, Y;

long gcd(long A, long B) {
    if (!B) {
        X = 1LL;
        Y = 0LL;
        return A;
    }

    long ans = gcd(B, A % B);

    long aux = X;
    X = Y;
    Y = aux - Y * (A / B);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long A, B;
    while (cin >> A >> B) {
        long D = gcd(A, B);
        cout << X << " " << Y << " " << D << "\n";
    }
}