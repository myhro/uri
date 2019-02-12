#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SuffixArray {
    private:
        string str;
        vector<int> suffixes;

    public:
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
                /* cout << i.second << ' ' << i.first << endl; */
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

bool compare(const string &a, const string &b) {
    return a.size() < b.size();
}

int main() {
    vector<SuffixArray> suffixes;
    vector<string> farm;
    string input;
    int n;
    int count;
    int biggest;
    int cur;
    int next;

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin.ignore();
        farm.clear();
        suffixes.clear();
        while (n > 0) {
            getline(cin, input);
            /* cout << input << endl; */
            farm.push_back(input);
            n--;
        }

        sort(farm.begin(), farm.end(), compare);
        for (auto s : farm) {
            suffixes.push_back(SuffixArray(s));
            cout << s << endl;
        }

        biggest = 0;
        for (int i = 0; i < (farm.size() - 1); i++) {
            count = 1;
            cur = i;
            next = cur + 1;
            while (next < farm.size()) {
                if (suffixes[next].check(farm[cur])) {
                    count++;
                    cur = next;
                    next = cur + 1;
                } else {
                    next++;
                }
            }
            if (count > biggest) {
                biggest = count;
            }
        }

        cout << biggest << endl;
        /* cout << farm.size() << endl; */
    }

    return 0;
}
