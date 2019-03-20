#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<string> in;
    unordered_set<string> out;
    bool invertible;
    bool function;
    string input;
    string left;
    string right;
    int delim;
    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        cin.ignore();
        in.clear();
        out.clear();
        function = true;
        invertible = true;
        while (n > 0) {
            getline(cin, input);
            delim = input.find("->");
            left = input.substr(0, delim - 1);
            right = input.substr(delim + 3);

            if (in.find(left) == in.end()) {
                in.insert(left);
            } else {
                function = false;
            }

            if (out.find(right) == out.end()) {
                out.insert(right);
            } else {
                invertible = false;
            }

            n--;
        }

        if (!function) {
            cout << "Not a function." << endl;
        } else if (!invertible) {
            cout << "Not invertible." << endl;
        } else {
            cout << "Invertible." << endl;
        }
    }

    return 0;
}
