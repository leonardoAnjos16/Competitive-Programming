#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n; cin >> n;

    bool happy = true;
    for (char c: n)
        if (!((c - '0') % 2))
            happy = false;

    cout << (happy ? "HAPPY" : "SAD") << "\n";
}