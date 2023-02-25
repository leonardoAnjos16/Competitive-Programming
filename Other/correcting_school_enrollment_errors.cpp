#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> ids;

    map<int, int> id_to_req;
    vector<vector<int>> requested(N + 1, vector<int>());

    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> B;

        ids.push_back(A);
        id_to_req[A] = i;

        requested[i].resize(B);
        for (int j = 0; j < B; j++)
            cin >> requested[i][j];

        sort(requested[i].begin(), requested[i].end());
    }

    map<int, int> id_to_rec;
    vector<vector<int>> received(M + 1, vector<int>());

    for (int i = 1; i <= M; i++) {
        int A, C;
        cin >> A >> C;

        ids.push_back(A);
        id_to_rec[A] = i;

        received[i].resize(C);
        for (int j = 0; j < C; j++)
            cin >> received[i][j];

        sort(received[i].begin(), received[i].end());
    }

    sort(ids.begin(), ids.end());
    ids.erase(unique(ids.begin(), ids.end()), ids.end());

    int X = 0, Y = 0, Z = 0;
    for (int id: ids) {
        int i = 0, j = 0;
        int req = id_to_req[id], rec = id_to_rec[id];
        int B = requested[req].size(), C = received[rec].size();

        vector<int> corrections;
        while (i < B || j < C) {
            if (i < B && j < C && requested[req][i] == received[rec][j]) i++, j++;
            else if (i < B && j < C && requested[req][i] < received[rec][j]) corrections.push_back(requested[req][i++]);
            else if (i < B && j < C) corrections.push_back(-received[rec][j++]);
            else if (i < B) corrections.push_back(requested[req][i++]);
            else corrections.push_back(-received[rec][j++]);
        }

        if (!corrections.empty()) {
            X++;

            cout << id;
            for (int correction: corrections) {
                cout << " ";
                if (correction < 0) cout << correction, Y++;
                else cout << "+" << correction, Z++;
            }

            cout << "\n";
        }
    }

    if (!X) cout << "GREAT WORK! NO MISTAKES FOUND!\n";
    else cout << "MISTAKES IN " << X << " STUDENTS: " << Y << " NOT REQUESTED, " << Z << " MISSED\n";
}