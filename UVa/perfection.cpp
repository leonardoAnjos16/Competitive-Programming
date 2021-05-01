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

int main() {
    printf("PERFECTION OUTPUT\n");

    int a;
    while (scanf("%d", &a), a) {
        int sum = a > 1;
        for (int i = 2; i * i <= a; i++) {
            if (!(a % i)) {
                sum += i + a / i;
                if (i * i == a) sum -= i;
            }
        }

        string ans = sum == a ? "PERFECT" : (sum < a ? "DEFICIENT" : "ABUNDANT");
        printf("%5d  %s\n", a, ans.c_str());
    }

    printf("END OF OUTPUT\n");
}