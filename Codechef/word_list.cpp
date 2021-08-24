#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool upper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool lower(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    string word;
    vector<string> words;

    while (cin >> word) {
        word += ".";
        string aux = "";

        for (char c: word) {
            if (lower(c)) aux += c;
            else if (upper(c)) aux += tolower(c);
            else if (aux != "") words.push_back(aux), aux = "";
        }
    }

    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());

    int ans = words.size();
    cout << ans << "\n";

    for (string s: words)
        cout << s << "\n";
}