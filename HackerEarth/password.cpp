#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int num_passwords;
    scanf("%d", &num_passwords);
    
    set<string> passwords;
    for (int i = 0; i < num_passwords; i++) {
        string password; cin >> password;
        passwords.insert(password);
    }
    
    string actual_password = "";
    for (set<string>::iterator it = passwords.begin(); it != passwords.end(); it++) {
        string password = *it;
        reverse(password.begin(), password.end());
        
        if (passwords.find(password) != passwords.end()) {
            actual_password = password;
            break;
        }
    }
    
    int size = actual_password.size();
    int middle = size / 2;
    printf("%d %c\n", size, actual_password[middle]);
}