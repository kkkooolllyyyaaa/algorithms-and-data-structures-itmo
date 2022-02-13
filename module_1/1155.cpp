#include <iostream>
#include <string>
#include <vector>

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"

using namespace std;
vector<string> ans;

int mi(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

void annihilate(int *a, int *b, const string &str) {
    int temp = mi(*a, *b);
    for (int i = 0; i < temp; ++i) {
        ans.push_back(str + '-');
    }
    *a -= temp;
    *b -= temp;
}

void move_diagonal(int *departure, int *destination, const string &path1, const string &path2) {
    for (int i = 0; i < *departure; ++i) {
        ans.push_back(path2 + '+');
        ans.push_back(path1 + '-');
    }
    *destination += *departure;
    *departure = 0;
}

int main() {
    io_boost;
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    if ((a + b + c + d + e + f + g + h) % 2 != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    annihilate(&a, &d, "AD");
    annihilate(&b, &c, "BC");
    annihilate(&e, &h, "EH");
    annihilate(&f, &g, "FG");

    annihilate(&a, &e, "AE");
    annihilate(&d, &h, "DH");
    annihilate(&b, &f, "BF");
    annihilate(&c, &g, "CG");

    annihilate(&a, &b, "AB");
    annihilate(&c, &d, "CD");
    annihilate(&e, &f, "EF");
    annihilate(&g, &h, "GH");

    move_diagonal(&g, &b, "GC", "CB");
    move_diagonal(&c, &f, "CB", "BF");

    move_diagonal(&h, &a, "HE", "EA");
    move_diagonal(&d, &e, "DA", "AE");

    annihilate(&a, &b, "AB");
    annihilate(&e, &f, "EF");
    annihilate(&b, &f, "BF");
    annihilate(&a, &e, "AE");
    if ((a + b + c + d + e + f + g + h) != 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (auto &an: ans) {
        cout << an << endl;
    }
    return 0;
}

