#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_words, num_job_descriptions;
    scanf("%d %d", &num_words, &num_job_descriptions);

    map<string, int> values;
    while (num_words--) {
        string word; int value;
        cin >> word >> value;
        values[word] = value;        
    }

    while (num_job_descriptions--) {
        string word;
        int total = 0;

        while (cin >> word && word != ".")
            if (values.find(word) != values.end())
                total += values[word];

        printf("%d\n", total);
    }
}