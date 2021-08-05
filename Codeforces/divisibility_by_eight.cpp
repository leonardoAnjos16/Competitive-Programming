#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n; cin >> n;
    for (int i = 0; i < (int) n.size(); i++)
        if (n[i] == '0' || n[i] == '8') {
            cout << "YES\n";
            cout << n[i] << "\n";
            return 0;
        }

    for (int i = 0; i < (int) n.size(); i++)
        if (n[i] != '0')
            for (int j = i + 1; j < (int) n.size(); j++) {
                string aux = "";
                aux += n[i];
                aux += n[j];

                int num = stoi(aux);
                if (!(num % 8)) {
                    cout << "YES\n";
                    cout << aux << "\n";
                    return 0;
                }
            }

    for (int i = 0; i < (int) n.size(); i++)
        if (n[i] != '0')
            for (int j = i + 1; j < (int) n.size(); j++)
                for (int k = j + 1; k < (int) n.size(); k++) {
                    string aux = "";
                    aux += n[i];
                    aux += n[j];
                    aux += n[k];

                    int num = stoi(aux);
                    if (!(num % 8)) {
                        cout << "YES\n";
                        cout << aux << "\n";
                        return 0;
                    }
                }

    cout << "NO\n";
}