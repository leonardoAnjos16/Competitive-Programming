#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool between(int a, int b, int c) {
    if (a > c) swap(a, c);
    return a <= b && b <= c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int XA, YA, XB, YB, XC, YC;
        cin >> XA >> YA >> XB >> YB >> XC >> YC;

        bool possible = false;
        if (XB == XA || XB == XC) possible = between(YA, YB, YC);
        else if (YB == YA || YB == YC) possible = between(XA, XB, XC);

        cout << (possible ? "YES" : "NO") << "\n";
    }
}