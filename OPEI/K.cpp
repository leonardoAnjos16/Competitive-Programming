#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; cin >> X;

    vector<tuple<int, int, string, string>> students(X);
    for (int i = 0; i < X; i++) {
        string name, cpf;
        int score, age;

        cin >> name >> cpf >> score >> age;
        students[i] = make_tuple(-score, -age, name, cpf);
    }

    sort(students.begin(), students.end());
    for (auto [_, __, name, cpf]: students)
        cout << name << " | " << cpf << "\n";
}