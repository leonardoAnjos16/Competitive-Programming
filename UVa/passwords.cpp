#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

int num_words;
string words[MAX];

void get_passwords(string rule, int size, int pos = 0, string password = "") {
    if (pos >= size) printf("%s\n", password.c_str());
    else if (rule[pos] == '0') {
        for (int i = 0; i < 10; i++) {
            string new_password = password + ((char) (i + '0'));
            get_passwords(rule, size, pos + 1, new_password);
        }
    } else {
        for (int i = 0; i < num_words; i++) {
            string new_password = password + words[i];
            get_passwords(rule, size, pos + 1, new_password);
        }
    }
}

int main() {
    while (scanf("%d", &num_words) != EOF) {
        for (int i = 0; i < num_words; i++)
            cin >> words[i];

        int num_rules;
        scanf("%d", &num_rules);
        printf("--\n");

        string rule;
        while (num_rules--) {
            cin >> rule;
            get_passwords(rule, (int) rule.size());
        }
    }
}