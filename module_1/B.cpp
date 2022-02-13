#include <iostream>
#include <cstddef>
#include <string>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

bool is_animal(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_trap(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_animal_and_trap(char a, char b) {
    return (is_trap(a) && is_animal(b)) || (is_trap(b) && is_animal(a));
}

bool equals_ignore_case(char a, char b) {
    if (is_trap(a))
        a = char(a - 'a');
    else
        a = char(a - 'A');
    if (is_trap(b))
        b = char(b - 'a');
    else
        b = char(b - 'A');
    return a == b;
}

typedef struct zoo_pointer {
    char c;
    int index;
} zoo_pointer;

int main() {
    io_boost;
    string zoo;
    cin >> zoo;

    size_t len = zoo.length();
    vector<zoo_pointer> balanced_entity_stack;
    vector<int> indexes(len / 2);
    int trap_id = 0, animal_id = 0;


    bool ans = true;
    for (size_t i = 0; i < len / 2; ++i) {
        if (!is_animal_and_trap(zoo[i], zoo[len - i - 1]) ||
            !equals_ignore_case(zoo[i], zoo[len - i - 1])) {
            ans = false;
            break;
        }
    }
    if (ans) {
        cout << "Possible" << endl;
        for (size_t i = len / 2; i >= 1; --i) {
            cout << i << ' ';
        }
        cout << endl;
        return 0;
    }


    for (size_t i = 0; i < len; ++i) {
        if (is_trap(zoo[i]))
            trap_id++;
        else
            animal_id++;

        if (balanced_entity_stack.empty()) {
            if (is_trap(zoo[i])) {
                balanced_entity_stack.push_back({.c = zoo[i], .index = trap_id});
            } else {
                balanced_entity_stack.push_back({.c = zoo[i], .index = animal_id});
            }
            continue;
        }

        zoo_pointer cur = balanced_entity_stack[balanced_entity_stack.size() - 1];
        char top = cur.c;

        if (is_animal_and_trap(top, zoo[i]) && equals_ignore_case(top, zoo[i])) {
            if (is_trap(zoo[i])) {
                indexes[trap_id - 1] = cur.index;
            } else {
                indexes[cur.index - 1] = animal_id;
            }
            balanced_entity_stack.pop_back();
        } else {
            if (is_trap(zoo[i])) {
                balanced_entity_stack.push_back({.c = zoo[i], .index = trap_id});
            } else {
                balanced_entity_stack.push_back({.c = zoo[i], .index = animal_id});
            }
        }

    }

    if (!balanced_entity_stack.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    for (int index: indexes)
        cout << index << ' ';
    cout << endl;
    return 0;
}
