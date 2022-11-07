#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n; cin >> n;
 
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[n - i - 1];
 
    stack<int> aux;
    vector<int> ans(n, 0);
 
    for (int i = 0; i < n; i++) {
        while (!aux.empty() && x[i] < x[aux.top()]) {
            ans[n - aux.top() - 1] = n - i;
            aux.pop();
        }
 
        aux.push(i);
    }
 
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
 
    cout << "\n";
}