#include <bits/stdc++.h>

using namespace std;

vector< vector<char> > possibilities;

void get_possibilities(string source, string target, int size, stack<char> anagram, vector<char> possibility, int push_counter = 0, int pop_counter = 0) {
    if (pop_counter == size) possibilities.push_back(possibility);
    else {
        if (push_counter < size) {
            anagram.push(source[push_counter]);
            possibility.push_back('i');
            get_possibilities(source, target, size, anagram, possibility, push_counter + 1, pop_counter);
            possibility.pop_back();
            anagram.pop();
        }

        if (!anagram.empty()) {
            char letter = anagram.top();
            anagram.pop();

            if (letter == target[pop_counter]) {
                possibility.push_back('o');
                get_possibilities(source, target, size, anagram, possibility, push_counter, pop_counter + 1);
                possibility.pop_back();
            }
        }
    }
}

int main() {
    string source, target;
    while (cin >> source >> target) {
        printf("[\n");

        if (source.size() == target.size()) {
            stack<char> anagram;
            vector<char> possibility;

            get_possibilities(source, target, source.size(), anagram, possibility);
            for (auto v: possibilities) {
                for (int i = 0; i < v.size(); i++) {
                    if (i > 0) printf(" ");
                    printf("%c", v[i]);
                }

                printf("\n");
            }
        }

        printf("]\n");
        possibilities.clear();
    }
}