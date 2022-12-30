#include <bits/stdc++.h>

using namespace std;

#define llong long long int

vector<string> ingredients;

void get_ingredients(int n) {
    cin.ignore();
    while (n--) {
        string line;
        getline(cin, line);

        int idx = 0;
        string ingredient = "";

        while (idx < (int) line.size() && line[idx] != ' ')
            ingredient += line[idx++];

        ingredients.push_back(ingredient);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M; cin >> M;
    get_ingredients(M);

    int N; cin >> N;
    get_ingredients(N);

    sort(ingredients.begin(), ingredients.end());
    ingredients.erase(unique(ingredients.begin(), ingredients.end()), ingredients.end());

    for (string ingredient: ingredients)
        cout << ingredient << "\n";
}