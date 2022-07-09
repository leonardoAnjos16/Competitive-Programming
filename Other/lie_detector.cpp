#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    vector<bool> truth(N);
    for (int i = N - 1; i >= 0; i--) {
        string S; cin >> S;
        truth[i] = S == "TRUTH";
    }

    bool ans = true;
    for (int i = 0; i < N; i++) {
        if (!ans) truth[i] = !truth[i];
        ans = truth[i];
    }

    cout << (ans ? "TRUTH" : "LIE") << "\n";
}