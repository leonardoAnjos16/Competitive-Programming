#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d", &num_cases);

    while (num_cases--) {
        int num_characters;
        scanf("%d\n", &num_characters);

        double values[256] = { 0 };
        while (num_characters--) {
            char character; int value;
            scanf("%c %d\n", &character, &value);
            values[character] = (double) value;
        }

        int num_lines;
        scanf("%d\n", &num_lines);

        double value = 0;
        while (num_lines--) {
            string line = "";
            getline(cin, line);

            int size = line.size();
            for (int i = 0; i < size; i++)
                value += values[line[i]];
        }

        value /= 100;
        printf("%.2lf$\n", value);
    }
}                                              