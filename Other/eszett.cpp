#include <bits/stdc++.h>

using namespace std;

string s;

void get_lowercase(int i = 0, string word = "") {
    if (i >= (int) s.size()) {
        cout << word << "\n";
        return;
    }

    char c = s[i] - 'A' + 'a';
    get_lowercase(i + 1, word + c);

    if (i + 1 < (int) s.size() && s[i] == 'S' && s[i + 1] == 'S')
        get_lowercase(i + 2, word + "B");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    get_lowercase();
}