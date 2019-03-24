#include <iostream>

using namespace std;

int main() {
    double x;

    cin >> x;
    cout.precision(4);
    cout << fixed;
    for (int i = 0; i < 100; i++) {
        cout << "N[" << i << "] = " << x << endl;
        x /= 2;
    }

    return 0;
}
