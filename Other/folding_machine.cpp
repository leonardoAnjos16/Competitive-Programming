#include <bits/stdc++.h>

using namespace std;

#define long long long int

int N, M;
vector<int> input, output;

bool possible() {
    if ((int) input.size() < M) return false;
    if ((int) input.size() == M) {
        bool equal = true;
        for (int i = 0; i < M && equal; i++)
            if (input[i] != output[i])
                equal = false;

        if (equal) return true;

        equal = true;
        for (int i = 0, j = M - 1; i < M; i++, j--)
            if (input[j] != output[i])
                equal = false;

        return equal;
    }

    if (*min_element(input.begin(), input.end()) > *max_element(output.begin(), output.end()))
        return false;

    for (int i = 1; i < (int) input.size(); i++) {
        vector<int> first;
        for (int j = 0; j < i; j++)
            first.push_back(j);

        vector<int> last;
        for (int j = (int) input.size() - 1; j >= i; j--)
            last.push_back(j);

        int size_first = first.size();
        int size_last = last.size();

        vector<int> aux = input;
        input.clear();

        int l = 0, r = 0;
        while (size_first - l > size_last)
            input.push_back(aux[first[l++]]);

        while (size_last - r > size_first)
            input.push_back(aux[last[r++]]);

        while (l < size_first)
            input.push_back(aux[first[l++]] + aux[last[r++]]);

        if (possible())
            return true;
        
        input = aux;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    input.resize(N);
    for (int i = 0; i < N; i++)
        cin >> input[i];

    cin >> M;

    output.resize(M);
    for (int i = 0; i < M; i++)
        cin >> output[i];

    cout << (possible() ? "S" : "N") << "\n";
}