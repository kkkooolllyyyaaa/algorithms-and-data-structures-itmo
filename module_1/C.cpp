#include <iostream>
#include <cstddef>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

bool block_start(const string &line) {
    return line == "{";
}

bool block_end(const string &line) {
    return line == "}";
}

bool number_assign(string line) {
    return line[line.length() - 1] >= '0' && line[line.length() - 1] <= '9';
}

bool temp_assign(string line) {
    return !number_assign(std::move(line));
}

int parse_number(string line) {
    size_t i = line.length() - 1;
    int digit = 1, res = 0;
    while (line[i] != '=') {
        if (line[i] == '-') {
            res *= -1;
            break;
        }
        res = res + digit * (line[i] - '0');
        digit *= 10;
        --i;
    }
    return res;
}

string parse_temp(string line) {
    string res;
    size_t i = 0;
    while (line[i] != '=') {
        res.push_back(line[i]);
        ++i;
    }
    return res;
}

string parse_second_temp(string line) {
    string res;
    size_t i = line.length() - 1;
    while (line[i] != '=') {
        res.push_back(line[i]);
        --i;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    io_boost;
    map<string, vector<int>> state_holder;
    vector<string> assigned_temps;
    vector<int> assigned_temps_cnt = {0};
    string line;
    while (cin >> line) {
        if (block_start(line)) {
            assigned_temps_cnt.push_back(0);
            continue;
        } else if (block_end(line)) {
            int cnt = assigned_temps_cnt.back();
            for (size_t i = assigned_temps.size() - 1; cnt > 0; --i) {
                state_holder.find(assigned_temps[i])->second.pop_back();
                assigned_temps.pop_back();
                --cnt;
            }
            assigned_temps_cnt.pop_back();
        } else if (number_assign(line)) {
            string temp1 = parse_temp(line);
            int number = parse_number(line);
            if (state_holder.find(temp1) == state_holder.end()) {
                state_holder[temp1].push_back(0);
            }
            assigned_temps_cnt.back()++;
            assigned_temps.push_back(temp1);
            state_holder[temp1].push_back(number);
        } else if (temp_assign(line)) {
            string temp1 = parse_temp(line);
            string temp2 = parse_second_temp(line);
            if (state_holder.find(temp1) == state_holder.end()) {
                state_holder[temp1].push_back(0);
            }
            if (state_holder.find(temp2) == state_holder.end()) {
                state_holder[temp2].push_back(0);
            }
            assigned_temps_cnt.back()++;
            assigned_temps.push_back(temp1);
            int value = state_holder[temp2].back();
            state_holder[temp1].push_back(value);
            cout << value << endl;
        }
    }
    return 0;
}
