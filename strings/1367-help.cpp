#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<char,vector<pair<int,string>>> subs;
    pair<int,string> score;
    char key;
    int n;
    int s;
    int p;

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        subs.clear();
        while (n > 0) {
            cin >> key;
            cin >> score.first;
            cin >> score.second;
            auto item = subs.find(key);
            if (item == subs.end()) {
                auto v = vector<pair<int,string>>();
                v.push_back(score);
                subs.insert({key, v});
            } else {
                item->second.push_back(score);
            }
            n--;
        }
        s = 0;
        p = 0;
        for (auto kv : subs) {
            auto correct = false;
            int incorrect = 0;
            for (auto i : kv.second) {
                if (i.second.compare("correct") == 0) {
                    correct = true;
                    p += i.first + incorrect * 20;
                } else {
                    incorrect++;
                }
            }
            if (correct) {
                s++;
            }
        }
        cout << s << " " << p << endl;
    }

    return 0;
}
