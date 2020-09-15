#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, string> dict;
    string line;

    while (getline(cin, line) && !line.empty()) {
        string english_word, foreign_word;
        english_word = foreign_word = "";

        int index = 0;
        while (line[index] != ' ') english_word += line[index++];
        while (++index < line.size()) foreign_word += line[index];

        dict[foreign_word] = english_word;
    }

    string foreign_word;
    while (cin >> foreign_word) {
        if (dict.find(foreign_word) == dict.end()) printf("eh\n");
        else printf("%s\n", dict[foreign_word].c_str());
    }
}