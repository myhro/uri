#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> attendance;
    vector<string> students;
    string input;
    bool first;
    int n;
    int m;

    cin >> n;
    while (n > 0) {
        cin >> m;
        attendance.clear();
        students.clear();
        for (int i = 0; i < m; i++) {
            cin >> input;
            students.push_back(input);
        }
        for (int i = 0; i < m; i++) {
            cin >> input;
            attendance.push_back(input);
        }
        first = true;
        for (int i = 0; i < m; i++) {
            int medical = count(attendance[i].begin(), attendance[i].end(), 'M');
            int present = count(attendance[i].begin(), attendance[i].end(), 'P');
            float total = attendance[i].size() - medical;
            if ((present / total) < 0.75) {
                if (!first) {
                    cout << " ";
                }
                cout << students[i];
                first = false;
            }
        }
        cout << endl;
        n--;
    }

    return 0;
}
