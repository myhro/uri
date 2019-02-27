#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SuffixArray {
    private:
        string str;
        vector<int> suffixes;

    public:
        SuffixArray() {}

        SuffixArray(string s) {
            vector<pair<string,int>> substrs;
            pair<string,int> sub;

            str = s;

            for (int i = 0; i < s.length(); i++) {
                sub.first = s.substr(i);
                sub.second = i;
                substrs.push_back(sub);
            }

            sort(substrs.begin(), substrs.end());

            for (auto i : substrs) {
                suffixes.push_back(i.second);
            }
        }

        bool check(string t) {
            string sub;
            int mid;
            int res;
            int l;
            int r;

            l = 0;
            r = str.length() - 1;
            while (l <= r) {
                mid = (l + r) / 2;
                sub = str.substr(suffixes[mid], t.length());
                res = t.compare(sub);
                if (res > 0) {
                    l = mid + 1;
                } else if (res < 0) {
                    r = mid - 1;
                } else {
                    return true;
                }
            }

            return false;
        }
};

int main() {
    SuffixArray suffix;
    int longest;
    string head;
    string tail;
    string w;

    while (cin >> w) {
        if (w.size() == 1) {
            cout << w << endl;
            continue;
        }
        longest = 0;
        for (int i = (w.size() - 1); i >= (w.size() / 2); i--) {
            head = w.substr(0, i);
            tail = w.substr(i);
            suffix = SuffixArray(head);
            if (suffix.check(tail)) {
                longest = tail.size();
            }
        }
        cout << w.substr(0, w.size() - longest) << endl;
    }

    return 0;
}
