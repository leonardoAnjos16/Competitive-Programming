#include <bits/stdc++.h>

using namespace std;

set<string> parse_words(string s) {
    int idx = 0;
    string word = "";
    set<string> words;

    while (idx < (int) s.size()) {
        if (s[idx] != ',') word += s[idx++];
        else {
            words.insert(word);
            word = "";
            idx += 2;
        }
    }

    words.insert(word);
    return words;
}

pair<string, set<string>> parse_symbol_words(string &s) {
    int idx = 0;
    string symbol = "";

    while (idx + 3 < (int) s.size() && (s[idx] != ' ' || s[idx + 1] != '-' || s[idx + 2] != '>' || s[idx + 3] != ' '))
        symbol += s[idx++];

    return make_pair(symbol, parse_words(s.substr(idx + 4)));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;
    cin.ignore();

    map<string, set<string>> sets;
    for (int i = 0; i < N; i++) {
        string s; getline(cin, s);

        auto [symbol, words] = parse_symbol_words(s);
        sets[symbol] = words;
    }

    string T; cin >> T;
    cin.ignore();

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        string phrase; getline(cin, phrase);

        string word;
        vector<string> words;
        stringstream ss(phrase);

        while (ss >> word)
            words.push_back(word);

        int sz = words.size();
        if (sz != (int) T.size()) cout << "Frase invalida\n";
        else {
            bool valid = true;
            for (int i = 0; i < sz && valid; i++) {
                string symbol = string(1, T[i]);
                if (sets[symbol].find(words[i]) == sets[symbol].end())
                    valid = false;
            }

            if (valid) ans++;
            else cout << "Frase invalida\n";
        }
    }

    if (!ans) cout << "Nenhuma das frases dadas sao validas\n";
    else cout << "Tivemos " << ans << " frases validas para a sequencia " << T << "\n";
}