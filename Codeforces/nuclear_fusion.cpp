#include <bits/stdc++.h>

using namespace std;

#define long long long int

int atomic_number(string &symbol) {
    if (symbol == "H") return 1;
    if (symbol == "He") return 2;
    if (symbol == "Li") return 3;
    if (symbol == "Be") return 4;
    if (symbol == "B") return 5;
    if (symbol == "C") return 6;
    if (symbol == "N") return 7;
    if (symbol == "O") return 8;
    if (symbol == "F") return 9;
    if (symbol == "Ne") return 10;
    if (symbol == "Na") return 11;
    if (symbol == "Mg") return 12;
    if (symbol == "Al") return 13;
    if (symbol == "Si") return 14;
    if (symbol == "P") return 15;
    if (symbol == "S") return 16;
    if (symbol == "Cl") return 17;
    if (symbol == "Ar") return 18;
    if (symbol == "K") return 19;
    if (symbol == "Ca") return 20;
    if (symbol == "Sc") return 21;
    if (symbol == "Ti") return 22;
    if (symbol == "V") return 23;
    if (symbol == "Cr") return 24;
    if (symbol == "Mn") return 25;
    if (symbol == "Fe") return 26;
    if (symbol == "Co") return 27;
    if (symbol == "Ni") return 28;
    if (symbol == "Cu") return 29;
    if (symbol == "Zn") return 30;
    if (symbol == "Ga") return 31;
    if (symbol == "Ge") return 32;
    if (symbol == "As") return 33;
    if (symbol == "Se") return 34;
    if (symbol == "Br") return 35;
    if (symbol == "Kr") return 36;
    if (symbol == "Rb") return 37;
    if (symbol == "Sr") return 38;
    if (symbol == "Y") return 39;
    if (symbol == "Zr") return 40;
    if (symbol == "Nb") return 41;
    if (symbol == "Mo") return 42;
    if (symbol == "Tc") return 43;
    if (symbol == "Ru") return 44;
    if (symbol == "Rh") return 45;
    if (symbol == "Pd") return 46;
    if (symbol == "Ag") return 47;
    if (symbol == "Cd") return 48;
    if (symbol == "In") return 49;
    if (symbol == "Sn") return 50;
    if (symbol == "Sb") return 51;
    if (symbol == "Te") return 52;
    if (symbol == "I") return 53;
    if (symbol == "Xe") return 54;
    if (symbol == "Cs") return 55;
    if (symbol == "Ba") return 56;
    if (symbol == "La") return 57;
    if (symbol == "Ce") return 58;
    if (symbol == "Pr") return 59;
    if (symbol == "Nd") return 60;
    if (symbol == "Pm") return 61;
    if (symbol == "Sm") return 62;
    if (symbol == "Eu") return 63;
    if (symbol == "Gd") return 64;
    if (symbol == "Tb") return 65;
    if (symbol == "Dy") return 66;
    if (symbol == "Ho") return 67;
    if (symbol == "Er") return 68;
    if (symbol == "Tm") return 69;
    if (symbol == "Yb") return 70;
    if (symbol == "Lu") return 71;
    if (symbol == "Hf") return 72;
    if (symbol == "Ta") return 73;
    if (symbol == "W") return 74;
    if (symbol == "Re") return 75;
    if (symbol == "Os") return 76;
    if (symbol == "Ir") return 77;
    if (symbol == "Pt") return 78;
    if (symbol == "Au") return 79;
    if (symbol == "Hg") return 80;
    if (symbol == "Tl") return 81;
    if (symbol == "Pb") return 82;
    if (symbol == "Bi") return 83;
    if (symbol == "Po") return 84;
    if (symbol == "At") return 85;
    if (symbol == "Rn") return 86;
    if (symbol == "Fr") return 87;
    if (symbol == "Ra") return 88;
    if (symbol == "Ac") return 89;
    if (symbol == "Th") return 90;
    if (symbol == "Pa") return 91;
    if (symbol == "U") return 92;
    if (symbol == "Np") return 93;
    if (symbol == "Pu") return 94;
    if (symbol == "Am") return 95;
    if (symbol == "Cm") return 96;
    if (symbol == "Bk") return 97;
    if (symbol == "Cf") return 98;
    if (symbol == "Es") return 99;
    if (symbol == "Fm") return 100;

    return 0;
}

int k;
vector<int> b, sums;
vector<vector<int>> memo;
vector<int> subsets;

bool possible(int available, int i = 0) {
    if (i >= k) return !available;

    int &ans = memo[available][i];
    if (~ans) return ans;

    int chosen = available;
    while (chosen) {
        if (sums[chosen] == b[i] && possible(available ^ chosen, i + 1)) {
            subsets.push_back(chosen);
            return ans = true;
        }

        chosen = (chosen - 1) & available;
    }

    return ans = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> k;

    vector<int> a(n);
    vector<string> original_atoms(n);

    for (int i = 0; i < n; i++) {
        cin >> original_atoms[i];
        a[i] = atomic_number(original_atoms[i]);;
    }

    sums.resize(1 << n);
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sums[i] += a[j];

    b.resize(n);
    vector<string> wanted_atoms(n);

    for (int i = 0; i < k; i++) {
        cin >> wanted_atoms[i];
        b[i] = atomic_number(wanted_atoms[i]);
    }

    memo.assign((1 << n) + 5, vector<int>(k + 5, -1));

    bool ans = possible((1 << n) - 1);
    if (!ans) cout << "NO\n";
    else {
        assert((int) subsets.size() == k);
        reverse(subsets.begin(), subsets.end());

        cout << "YES\n";
        for (int i = 0; i < k; i++) {
            bool first = false;
            for (int j = 0; j < n; j++)
                if (subsets[i] & (1 << j)) {
                    if (first) cout << "+";
                    cout << original_atoms[j];
                    first = true;
                }

            cout << "->" << wanted_atoms[i] << "\n";
        }
    }
}