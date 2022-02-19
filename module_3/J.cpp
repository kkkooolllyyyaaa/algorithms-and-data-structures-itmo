#include <iostream>
#include <deque>

using namespace std;

void process_even(deque<int> *q1, deque<int> *q2);

int main() {
    int n;
    cin >> n;

    deque<int> q1;
    deque<int> q2;
    char operation;
    int number, cnt = 0;

    for (int i = 0; i < n; ++i) {
        cin >> operation;
        if (operation == '-') {
            cout << q1.front() << endl;
            q1.pop_front();
            if (cnt % 2 == 0)
                process_even(&q1, &q2);

            --cnt;
            continue;
        }
        cin >> number;
        if (operation == '+') {
            q2.push_back(number);
            if (cnt % 2 == 0)
                process_even(&q1, &q2);

        } else {
            q2.push_front(number);
            if (cnt % 2 == 0)
                process_even(&q1, &q2);

        }
        ++cnt;
    }
    return 0;
}

void process_even(deque<int> *q1, deque<int> *q2) {
    int mid = (*q2).front();
    (*q2).pop_front();
    (*q1).push_back(mid);
}
