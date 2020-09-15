#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> words;
    string line;

    while (getline(cin, line)) {
        string word = "";
        int index = 0;

        while (index < line.size()) {
            if (line[index] >= 'A' && line[index] <= 'Z')
                line[index] = line[index] - 'A' + 'a';

            if (line[index] >= 'a' && line[index] <= 'z') word += line[index];
            else {
                if (word != "") words.insert(word);
                word = "";
            }

            index++;
        }

        if (word != "") words.insert(word);
    }

    for (set<string>::iterator it = words.begin(); it != words.end(); it++)
        printf("%s\n", (*it).c_str());
}