#include <bits/stdc++.h>

using namespace std;

#define long long long int

const long MAX = 1e18 + 5;

vector<long> facts;
set<long> profacts;

void get_profacts(long n = 1LL, int i = 2) {
    profacts.insert(n);
    for (int j = i; j < 20 && facts[j] <= MAX / n; j++) {
        // n * f <= MAX
        // f <= MAX / n
        get_profacts(n * facts[j], j);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    facts.assign(20, 1LL);
    for (int i = 2; i < 20; i++)
        facts[i] = facts[i - 1] * i;

    get_profacts();

    int n; cin >> n;
    while (n--) {
        long a; cin >> a;

        bool profact = profacts.count(a);
        cout << (profact ? "YES" : "NO") << "\n";
    }
}