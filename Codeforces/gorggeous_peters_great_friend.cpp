#include <bits/stdc++.h>

using namespace std;

#define long long long int

#define pii pair<int, int>
#define pll pair<long, long>
#define fst first
#define snd second

#define all(ds) (ds).begin(), (ds).end()
#define size(ds) (int) (ds).size()

#define pq priority_queue
#define vi vector<int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int MAX = 5e4 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, P, S;
    cin >> C >> P >> S;

    string handles[MAX];
    for (int i = 0; i < C; i++)
        cin >> handles[i];

    map<string, int> scores;
    for (int i = 0; i < P; i++) {
        string id; int score;
        cin >> id >> score;
        scores[id] = score;
    }

    map<string, int> user_score;
    for (int i = 0; i < S; i++) {
        string user, problem, verdict;
        cin >> user >> problem >> verdict;

        if (verdict == "AC")
            user_score[user] += scores[problem];
    }

    for (int i = 0; i < C; i++)
        cout << handles[i] << " " << user_score[handles[i]] << "\n";
}