#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int last = 0;
    bool fishy = false;

    for (int i = 0; i < n; i++) {
        string word; cin >> word;

        if (word == "mumble") last++;
        else if (stoi(word) != last + 1) fishy = true;
        else last++;
    }

    cout << (fishy ? "something is fishy" : "makes sense") << "\n";
}