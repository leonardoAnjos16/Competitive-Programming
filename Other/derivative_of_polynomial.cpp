#include <bits/stdc++.h>

using namespace std;

#define long long long int

bool is_separator(string &polynomial, int i) {
    return polynomial[i] == '+' || (polynomial[i] == '-' && polynomial[i - 1] != '^');
}

pair<int, int> parse_term(string term) {
    string coefficient_str = "";
    int idx = 0, n = term.size();

    while (idx < n && term[idx] != 'x')
        coefficient_str += term[idx++];

    int coefficient = 1;
    if (coefficient_str == "-") coefficient = -1;
    else if (!coefficient_str.empty() && coefficient_str != "+")
        coefficient = stoi(coefficient_str);

    if (idx >= n) return make_pair(0, coefficient);

    idx += 2;
    string exponent_str = "";

    while (idx < n)
        exponent_str += term[idx++];

    int exponent = exponent_str.empty() ? 1 : stoi(exponent_str);
    return make_pair(exponent, coefficient);
}

map<int, int> parse_polynomial(string polynomial) {
    string curr = "";
    map<int, int> exp_to_coeff;
    int idx = 0, n = polynomial.size();

    while (idx < n) {
        curr += polynomial[idx++];
        while (idx < n && !is_separator(polynomial, idx))
            curr += polynomial[idx++];

        auto [exponent, coefficient] = parse_term(curr);
        exp_to_coeff[exponent] += coefficient;
        curr = "";
    }

    return exp_to_coeff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    map<int, int> exp_to_coeff = parse_polynomial(s);

    map<int, int> derivative;
    for (auto [exp, coeff]: exp_to_coeff)
        derivative[exp - 1] = exp * coeff;

    string ans = "";
    bool first = true;

    for (auto [exp, coeff]: derivative) {
        if (!coeff) continue;

        if (coeff != 1 || !exp) {
            if (!first && coeff > 0)
                ans += "+";
            
            ans += to_string(coeff);
        }

        if (exp) {
            ans += "x";
            if (exp != 1)
                ans += "^" + to_string(exp);
        }

        first = false;
    }

    if (ans.empty()) cout << "0\n";
    else cout << ans << "\n";
}