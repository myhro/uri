#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> a;
    stack<int> b;
    bool valid;
    bool run;
    int tmp;
    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        run = true;
        while (run) {
            while (!a.empty()) {
                a.pop();
            }
            while (!b.empty()) {
                b.pop();
            }
            for (int i = n; i > 0; i--) {
                a.push(i);
            }
            tmp = 0;
            valid = true;
            for (int i = 0; i < n; i++) {
                cin >> tmp;
                if (tmp == 0) {
                    run = false;
                    break;
                }
                if (!valid) {
                    continue;
                }
                while(!a.empty() && (a.top() < tmp)) {
                    b.push(a.top());
                    a.pop();
                }
                if (!a.empty() && (a.top() == tmp)) {
                    a.pop();
                } else if (!b.empty() && (b.top() == tmp)) {
                    b.pop();
                } else {
                    valid = false;
                }
            }
            if (tmp != 0) {
                if (valid) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
