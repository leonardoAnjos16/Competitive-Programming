#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        vector<int> B(N);
        for (int i = 0; i < N; i++)
            cin >> B[i];

        int mn = INT_MAX;
        vector<int> indices;

        for (int i = 0; i < N; i++) {
            int aux = (A[0] + B[i]) % N;
            if (aux < mn) {
                mn = aux;
                indices.clear();
            }
            
            if (aux <= mn) indices.push_back(i);
        }

        vector<int> ans(N, INT_MAX);
        for (auto i: indices) {
            vector<int> C(N);
            for (int j = 0; j < N; j++)
                C[j] = (A[j] + B[(j + i) % N]) % N;

            int idx = 0;
            while (idx < N && C[idx] == ans[idx]) idx++;
            if (idx < N && C[idx] < ans[idx]) ans = C;
        }

        for (int i = 0; i < N; i++) {
            if (i) cout << " ";
            cout << ans[i];
        }

        cout << "\n";
    }
}