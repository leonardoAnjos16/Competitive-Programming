#include <bits/stdc++.h>

using namespace std;

const int NUM = 1;
const int COLOR = 2;

int played(int table_num, string &table_color, vector<int> &nums, vector<string> &colors, int sequence_type) {
    int ans = 0;
    for (int i = 0; i < (int) nums.size(); i++) {
        if (sequence_type == NUM && nums[i] == table_num) ans++;
        else if (sequence_type == COLOR && colors[i] == table_color) ans++;
    }

    return ans;
}

void play(int table_num, string &table_color, vector<int> &nums, vector<string> &colors, int sequence_type) {
    vector<int> left_nums;
    vector<string> left_colors;

    int left = (int) nums.size();
    for (int i = 0; i < (int) nums.size(); i++) {
        if ((sequence_type == NUM && nums[i] == table_num) || (sequence_type == COLOR && colors[i] == table_color)) {
            cout << "- Jogou a carta " << nums[i] << " da cor " << colors[i] << "\n";
            if (--left == 1) cout << "- UNU!\n";
        } else {
            left_nums.push_back(nums[i]);
            left_colors.push_back(colors[i]);
        }
    }

    if (!left) cout << "- Bati!\n";
    else {
        cout << "Ainda ficou com a(s) seguintes(s) carta(s) na mao:\n";
        for (int i = 0; i < (int) left_nums.size(); i++)
            cout << "- " << left_nums[i] << " " << left_colors[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int table_num; cin >> table_num;
    string table_color; cin >> table_color;

    vector<int> nums;
    vector<string> colors;

    int num; string color;
    while (cin >> num, num) {
        cin >> color;

        nums.push_back(num);
        colors.push_back(color);
    }

    if (nums.empty()) cout << "Voce ja bateu!\n";
    else {
        cout << "Eh melhor jogar uma sequencia de ";
        if (played(table_num, table_color, nums, colors, NUM) > played(table_num, table_color, nums, colors, COLOR)) {
            cout << "numeros\n";
            play(table_num, table_color, nums, colors, NUM);
        } else {
            cout << "cores\n";
            play(table_num, table_color, nums, colors, COLOR);
        }
    }
}