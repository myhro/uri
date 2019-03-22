#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> &tree, int i) {
    int total;

    total = 0;
    while (i > 0) {
        total += tree[i];
        i -= i & (-i);
    }

    return total;
}

void add(vector<int> &tree, int i, int k) {
    while(i < tree.size()) {
        tree[i] += k;
        i += i & (-i);
    }
}

int count(vector<int> &v) {
    int total;
    vector<int> tree(v.size(), 0);

    total = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        total += sum(tree, v[i] - 1);
        add(tree, v[i], 1);
    }

    return total;
}

int main() {
    int n;
    int tmp;
    vector<int> input;

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        input.clear();
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            input.push_back(tmp);
        }
        if ((count(input) % 2) == 0) {
            cout << "Carlos" << endl;
        } else {
            cout << "Marcelo" << endl;
        }
    }

    return 0;
}
