#include <bits/stdc++.h>

using namespace std;

int main() {
    int num_cases;
    scanf("%d\n\n", &num_cases);

    while (num_cases--) {
        vector<string> fragments;
        int size = 0;

        string fragment;
        while (getline(cin, fragment) && !fragment.empty()) {
            fragments.push_back(fragment);
            size += fragment.size();
        }

        int num_fragments = fragments.size();
        size /= (num_fragments >> 1);

        map<string, int> combinations;
        for (int i = 0; i < num_fragments; i++) {
            for (int j = 0; j < num_fragments; j++) {
                if (i != j && (fragments[i].size() + fragments[j].size()) == size) {
                    string combination = fragments[i] + fragments[j];
                    if (combinations.find(combination) == combinations.end()) combinations[combination] = 1;
                    else combinations[combination]++;
                }
            }
        }

        string answer = "";
        for (map<string, int>::iterator it = combinations.begin(); it != combinations.end(); it++)
            if (answer == "" || it->second > combinations[answer])
                answer = it->first;

        printf("%s\n", answer.c_str());
        if (num_cases > 0) printf("\n");
    }
}