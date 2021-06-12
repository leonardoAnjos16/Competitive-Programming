#include <bits/stdc++.h>

using namespace std;

#define long long long int

int count_hahas(string &str) {
    int hahas = 0, n = str.size();
    for (int i = 3; i < n; i++)
        if (str[i - 3] == 'h' && str[i - 2] == 'a' && str[i - 1] == 'h' && str[i] == 'a')
            hahas++;

    return hahas;
}

int count_hahas(string &s, string &t) {
    int m = s.size(), n = t.size(), hahas = 0;
    if (m >= 3 && s[0] == 'h' && s[1] == 'a' && s[2] == 'h' && t[0] == 'a') hahas++;
    if (m >= 2 && n >= 2 && s[m - 2] == 'h' && s[m - 1] == 'a' && t[0] == 'h' && t[1] == 'a') hahas++;
    if (n >= 3 && s[m - 1] == 'h' && t[0] == 'a' && t[1] == 'h' && t[2] == 'a') hahas++;
    return hahas;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        string last_name;
        map<string, tuple<long, string, string>> vars;

        while (n--) {
            string name, op;
            cin >> name >> op;

            last_name = name;
            if (op == ":=") {
                string value; cin >> value;

                long hahas = count_hahas(value);
                string begin = value.substr(0, 3);

                reverse(value.begin(), value.end());
                string end = value.substr(0, 3);
                reverse(end.begin(), end.end());

                vars[name] = make_tuple(hahas, begin, end);
            } else {
                string operand1, plus, operand2;
                cin >> operand1 >> plus >> operand2;

                long h1; string b1, e1;
                tie(h1, b1, e1) = vars[operand1];

                long h2; string b2, e2;
                tie(h2, b2, e2) = vars[operand2];

                long hahas = h1 + h2 + count_hahas(e1, b2);

                string aux = e1 + b2;
                string begin = (int) b1.size() < 3 ? aux.substr(0, 3) : b1;

                string end = e2;
                if ((int) e2.size() < 3) {
                    reverse(aux.begin(), aux.end());
                    end = aux.substr(0, 3);
                    reverse(end.begin(), end.end());
                }

                vars[name] = make_tuple(hahas, begin, end);
            }
        }

        long ans = get<0>(vars[last_name]);
        cout << ans << "\n";
    }
}