#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    string s, t;
    cin >> s >> t;

    if (!(N & 1) && s == t) cout << "Deletion succeeded\n";
    else {
        int sz = t.size();
        for (int i = 0; i < sz; i++)
            t[i] = t[i] == '1' ? '0' : '1';

        if ((N & 1) && s == t) cout << "Deletion succeeded\n";
        else cout << "Deletion failed\n";
    }
}