#include <bits/stdc++.h>

using namespace std;

const int MAX = 5;

string P[MAX][MAX], T[MAX];

void print_words(char type) {
    vector<string> words;
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            if (T[i][j] == type)
                words.push_back(P[i][j]);

    sort(words.begin(), words.end());
    for (int i = 0; i < (int) words.size(); i++) {
        if (i) cout << " ";
        cout << words[i];
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cin >> P[i][j];

    for (int i = 0; i < MAX; i++)
        cin >> T[i];

    print_words('V');
    print_words('A');
    print_words('N');
    print_words('E');
}