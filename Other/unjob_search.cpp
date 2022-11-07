#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int b = 2;
    for (int c = 3; c <= N; c++) {
        cout << "? 1 " << b << " " << c << "\n";
        cout.flush();

        int inPath; cin >> inPath;
        if (inPath) b = c;
    }

    cout << "! " << b << "\n";
    cout.flush();
}