#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    sort(words.begin(), words.end());

    string palindrome = "", middle = "";
    for (int i = 0; i < n; i++) {
        string reversed = words[i];
        reverse(reversed.begin(), reversed.end());

        if (binary_search(words.begin() + i + 1, words.end(), reversed)) palindrome += words[i];
        else if (words[i] == reversed) middle = words[i];
    }

    string reversed = palindrome;
    reverse(reversed.begin(), reversed.end());

    palindrome += middle + reversed;
    int size = palindrome.size();

    printf("%d\n", size);
    printf("%s\n", palindrome.c_str());
}