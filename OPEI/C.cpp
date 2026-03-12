#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string password; cin >> password;

    string attempt;
    int attempts = 0;
    bool done = false;

    while (cin >> attempt && ++attempts <= 10 && !done) {
        assert(attempt.size() == password.size());

        string coder = "";
        vector<bool> correct(password.size(), false);

        for (int i = 0; i < (int) password.size(); i++)
            if (attempt[i] == password[i]) {
                coder += 'b';
                correct[i] = true;
            }

        int dashes = 0;
        vector<bool> misplaced(password.size(), false);

        for (int i = 0; i < (int) password.size(); i++) {
            if (correct[i]) continue;

            bool found = false;
            for (int j = 0; j < (int) password.size() && !found; j++)
                if (!correct[j] && !misplaced[j] && attempt[i] == password[j]) {
                    coder += 'w';
                    found = true;
                    misplaced[j] = true;
                }

            if (!found) dashes++;
        }

        coder += string(dashes, '-');
        cout << coder << "\n";

        done = true;
        for (int i = 0; i < (int) password.size() && done; i++)
            if (coder[i] != 'b') done = false;

        if (done) {
            if (attempts == 1) cout << "Sherlock?!! Voce conseguiu advinhar a senha de primeira!!! GENIAL!!!\n";
            else if (attempts == 10) cout << "Ufa! Essa foi por pouco mas voce finalmente conseguiu adivinhar a senha!\n";
            else cout << "Voce conseguiu decifrar a senha em " << attempts << " tentativas!! Parabens!!\n";
        }
    }

    if (!done) cout << "Infelizmente nao foi dessa vez... Quem sabe da proxima voce consegue decifrar a senha?\n";
}