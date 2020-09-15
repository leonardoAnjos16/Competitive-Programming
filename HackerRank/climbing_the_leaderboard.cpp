#include <bits/stdc++.h>

using namespace std;

int main() {
    int numCompetitors, score;
    cin >> numCompetitors >> score;

    vector<int> scores;
    scores.push_back(score);

    int rank = 0;
    for (int i = 1; i < numCompetitors; i++) {
        cin >> score;
        if (score < scores[rank]) {
            scores.push_back(score);
            rank++;
        }
    }

    int numAttempts;
    cin >> numAttempts;
    for (int i = 0; i < numAttempts; i++) {
        cin >> score;
        rank++;

        while (rank > 0 && scores[rank - 1] <= score) rank--;
        cout << (rank + 1) << endl;
    }

    return 0;
}