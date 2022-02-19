#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_animal(char c);

bool is_trap(char c);

bool is_animal_and_trap(char a, char b);

bool equals_ignore_case(char a, char b);

struct zoo_pointer {
    char c;
    size_t index;
};

int main() {
    string zoo;
    cin >> zoo;

    size_t len = zoo.length();
    bool ans = true;

    /**
     * Если это палиндром относительно прописных и строчных букв, то выводим ответ
     * Иначе проверим на правильную скобочную последовательность
     */
    for (size_t i = 0; i < len / 2; ++i) {
        if (!is_animal_and_trap(zoo[i], zoo[len - i - 1]) || !equals_ignore_case(zoo[i], zoo[len - i - 1])) {
            ans = false;
            break;
        }
    }
    if (ans) {
        cout << "Possible" << endl;
        for (size_t i = len / 2; i >= 1; --i) {
            cout << i << ' ';
        }
        return 0;
    }

    /**
     * Если строка - правильная скобочная последовательность относительно строчных и прописных букв,
     * тогда мы можем отобразить это на окружность и провести непересекающиеся линии
     * a, b, ..., z <=> "("
     * A, B, ..., Z <=> ")"
     */

    vector<struct zoo_pointer> balanced_entity_stack;
    vector<size_t> indexes(len / 2);
    size_t trap_id = 0, animal_id = 0;

    for (size_t i = 0; i < len; ++i) {
        trap_id += is_trap(zoo[i]);
        animal_id += is_animal(zoo[i]);

        size_t assigned_index = trap_id;
        if (is_animal(zoo[i]))
            assigned_index = animal_id;

        if (balanced_entity_stack.empty()) {
            balanced_entity_stack.push_back({.c = zoo[i], .index = assigned_index});
            continue;
        }

        struct zoo_pointer current = balanced_entity_stack[balanced_entity_stack.size() - 1];
        char top = current.c;

        if (is_animal_and_trap(top, zoo[i]) && equals_ignore_case(top, zoo[i])) {
            if (is_trap(zoo[i]))
                indexes[trap_id - 1] = current.index;
            else
                indexes[current.index - 1] = animal_id;
            balanced_entity_stack.pop_back();
            continue;
        }
        balanced_entity_stack.push_back({.c = zoo[i], .index = assigned_index});
    }

    if (!balanced_entity_stack.empty()) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (size_t index: indexes)
            cout << index << ' ';
    }
    return 0;
}

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