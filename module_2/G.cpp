#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct weight_and_char {
    size_t weight;
    char c;
    size_t cnt;
} element;

bool comp(element e1, element e2) {
    return e1.weight > e2.weight;
}

int main() {
    string str;
    cin >> str;

    /**
     * Посчитаем сколько каждой из букв
     */
    const int alphabet_sz = 26;
    vector<size_t> char_cnt(alphabet_sz, 0);
    for (char i: str)
        char_cnt[i - 'a']++;

    /**
     * Отсортируем все буквы по весам, независимо от количества
     */
    vector<element> weights(alphabet_sz);
    for (int i = 0; i < alphabet_sz; ++i) {
        size_t weight;
        cin >> weight;
        weights[i] = (element)
                {
                        .weight = weight,
                        .c = char('a' + i),
                        .cnt = char_cnt[i]
                };
    }
    sort(weights.begin(), weights.end(), comp);

    /**
     * Если букв хотя бы 2, то припишем их слева и справа
     * Так мы получим максимальную пользу от конкретной буквы с весом
     * Если букв меньше 2, то они нам не важны, засунем их позже в центр
     */
    vector<char> ans(str.length());
    size_t left = 0, right = ans.size() - 1;
    for (size_t i = 0; i < alphabet_sz; ++i) {
        if (weights[i].cnt < 2)
            continue;

        ans[left] = weights[i].c;
        ans[right] = weights[i].c;
        --right;
        ++left;
    }

    /**
     * Припишем оставшиеся незначимые буквы
     */
    for (size_t i = 0; i < alphabet_sz; ++i) {
        if (weights[i].cnt == 1) {
            ans[left] = weights[i].c;
            ++left;
        } else if (weights[i].cnt > 2) {
            for (size_t j = 0; j < weights[i].cnt - 2; ++j) {
                ans[left] = weights[i].c;
                ++left;
            }
        }
    }

    for (char an: ans)
        cout << an;

    return 0;
}
