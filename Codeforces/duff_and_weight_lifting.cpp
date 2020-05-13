#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int main() {
    int n; scanf("%d", &n);

    int w[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    sort(w, w + n);

    stack<int> aux;
    aux.push(w[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        if (aux.top() != w[i]) aux.push(w[i]);
        else {
            do aux.pop(), w[i]++;
            while (!aux.empty() && w[i] == aux.top());
            aux.push(w[i]);
        }
    }

    int ans = aux.size();
    printf("%d\n", ans);
}