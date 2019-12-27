#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    int counter = 1;

    while (cin >> input && input != "#") {
        string language;
        if (input == "HELLO") language = "ENGLISH";
        else if (input == "HOLA") language = "SPANISH";
        else if (input == "HALLO") language = "GERMAN";
        else if (input == "BONJOUR") language = "FRENCH";
        else if (input == "CIAO") language = "ITALIAN";
        else if (input == "ZDRAVSTVUJTE") language = "RUSSIAN";
        else language = "UNKNOWN";

        cout << "Case " << counter++ << ": " << language << endl;
    }
}