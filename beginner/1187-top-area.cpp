#include <iostream>

using namespace std;

int main() {
    char o;
    double total;
    double tmp;
    int count;
    int n;

    cin >> o;
    count = 0;
    n = 12;
    total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if ((j > i) && (j < (n - 1 - i))) {
                count++;
                total += tmp;
            }
        }
    }

    cout << fixed;
    cout.precision(1);
    if (o == 'S') {
        cout << total << endl;
    } else {
        cout << total / count << endl;
    }

    return 0;
}
