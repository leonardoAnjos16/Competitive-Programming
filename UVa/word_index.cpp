#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 5

map<string, int> mapper;
int word_index = 1;

void fill_mapper(string word = "a", int letter_index = 0) {
    if (word.size() > MAX_SIZE) return;

    int last_letter = 'z' - (word.size() - letter_index) + 1;
    if (letter_index == 0) {
        for (int c = 'a'; c <= last_letter; c++) {
            word[letter_index] = (char) c;
            fill_mapper(word, letter_index + 1);
        }

        word = 'a' + word;
        fill_mapper(word);
    } else if (letter_index < word.size()) {
        for (int c = word[letter_index - 1] + 1; c <= last_letter; c++) {
            word[letter_index] = (char) c;
            fill_mapper(word, letter_index + 1);
        }
    }
    else mapper[word] = word_index++;
}

int main() {
    fill_mapper();

    string word;
    while (cin >> word) {
        if (mapper.find(word) == mapper.end()) printf("0\n");
        else printf("%d\n", mapper[word]);
    }
}