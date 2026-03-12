#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool successful = true;
    for (int i = 0; i < 8 && successful; i++) {
        int N; cin >> N;
        if (N == 9)
            successful = false;
    }

    cout << (successful ? "S" : "F") << "\n";
}