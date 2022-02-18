#include <iostream>
#include <vector>
#include <queue>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;

// Номера вхождений для каждой машины в порядке поступления
vector<queue<int>> cars;

// Бинарная мин куча
// В задаче, top() => элемент, который выгоднее убрать с пола (т.е. он дальше всех или вовсе больше не используется)
class BiHeap {
private:
    vector<int> heap;
    vector<int> ids;

    int left(int parent);

    int right(int parent);

    int parent(int child);

public:
    BiHeap(int n) {
        ids.resize(n, -1);
    }

    void insert(int element);

    void sift_up(int index);

    void sift_down(int index);

    void pop();

    int top();

    int index_by_id(int id);
};


bool cmp(int car1, int car2);

int main() {
    io_boost;
    int n, k, p;
    cin >> n >> k >> p;

    int answer = 0, floor_cnt = 0;
    vector<bool> floor(n, false);
    cars.resize(n);
    BiHeap heap(n);
    vector<int> queries(p);

    // Заполняем вхождения каждой из машин
    for (int i = 0; i < p; ++i) {
        int car;
        cin >> car;
        queries[i] = --car;
        cars[queries[i]].push(i);
    }

    for (int i = 0; i < p; ++i) {
        const int car = queries[i];
        // Если машина уже на полу, то просто обновим её позицию в куче (т.к. состояние очереди поменялось)
        if (floor[car]) {
            cars[car].pop();
            int to_sift = heap.index_by_id(car);
            heap.sift_up(to_sift);
            continue;
        }
        // Добавим элемент в кучу
        if (floor_cnt < k) {
            cars[car].pop();
            heap.insert(car);
            floor_cnt++;
            floor[car] = true;
        }
        // Уберем наиболее выгодную машину (top кучи) и добавим машину с запроса
        else {
            const int to_pop = heap.top();
            floor[to_pop] = false;
            heap.pop();

            cars[car].pop();
            heap.insert(car);
            floor[car] = true;
        }
        answer++;
    }
    cout << answer << endl;
    return 0;
}


int BiHeap::parent(int child) {
    if (child == 0 || child >= heap.size())
        return -1;
    return (child - 1) / 2;
}

int BiHeap::left(int parent) {
    int ret = parent * 2 + 1;
    if (ret >= heap.size())
        return -1;
    return ret;
}

int BiHeap::right(int parent) {
    int ret = parent * 2 + 2;
    if (ret >= heap.size())
        return -1;
    return ret;
}

void BiHeap::sift_up(int index) {
    int p = parent(index);
    if (index >= 0 && p >= 0 && cmp(heap[index], heap[p])) {
        swap(ids[heap[index]], ids[heap[p]]);
        swap(heap[index], heap[p]);
        sift_up(p);
    }
}

void BiHeap::sift_down(int index) {
    int l = left(index), r = right(index), mi_i = l;
    if (l < 0)
        return;
    if ((l > 0 && r > 0) && cmp(heap[r], heap[l]))
        mi_i = r;

    if (cmp(heap[mi_i], heap[index])) {
        swap(ids[heap[mi_i]], ids[heap[index]]);
        swap(heap[mi_i], heap[index]);
        sift_down(mi_i);
    }
}

void BiHeap::insert(int element) {
    heap.push_back(element);
    ids[element] = heap.size() - 1;
    sift_up(heap.size() - 1);
}

void BiHeap::pop() {
    if (heap.empty())
        return;

    heap[0] = heap.back();
    ids[heap.front()] = 0;
    ids[heap.back()] = -1;
    heap.pop_back();
    sift_down(0);
}

int BiHeap::top() {
    if (heap.empty())
        return -1;
    return heap.front();
}

int BiHeap::index_by_id(int id) {
    return ids[id];
}

// is car1 < car2 ?
bool cmp(int car1, int car2) {
    if (!cars[car1].empty() && !cars[car2].empty()) {
        return cars[car1].front() > cars[car2].front();
    }
    if (cars[car1].empty())
        return true;
    else if (cars[car2].empty())
        return false;
    return false;
}