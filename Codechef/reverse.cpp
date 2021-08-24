#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    cin.ignore();

    vector<vector<string>> lines;
    for (int i = 0; i < N; i++) {
        string line; getline(cin, line);

        vector<string> words;
        stringstream ss(line);

        string word;
        while (ss >> word) {
            word += ".";
            string aux = "";

            for (auto c: word) {
                if (letter(c)) aux += c;
                else if (aux != "") {
                    words.push_back(aux);
                    aux = "";
                }
            }
        }

        reverse(words.begin(), words.end());
        lines.push_back(words);
    }

    reverse(lines.begin(), lines.end());

    for (auto v: lines) {
        int sz = v.size();
        for (int i = 0; i < sz; i++) {
            if (i) cout << " ";
            cout << v[i];
        }

        cout << "\n";
    }
}