#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);

    int idx = 0;
    string ans = "";

    while (idx < (int) line.size()) {
        string word = "";
        while (idx < (int) line.size() && line[idx] != ' ')
            word += line[idx++];

        if (word == "blue") word = "azul";
        else if (word == "red") word = "vermelho";

        ans += word;
        while (idx < (int) line.size() && line[idx] == ' ')
            ans += line[idx++];
    }

    cout << ans << "\n";
}