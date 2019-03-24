#include <iostream>

using namespace std;

int main() {
    string s;
    int l;
    int n;
    int r;

    cin >> n;
    cin.ignore();
    while (n > 0) {
        getline(cin, s);
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i]) || isupper(s[i])) {
                s[i] += 3;
            }
        }
        l = 0;
        r = s.length() - 1;
        while (l <= r) {
            swap(s[l], s[r]);
            s[r] -= 1;
            l++;
            r--;
        }
        cout << s << endl;
        n--;
    }

    return 0;
}
