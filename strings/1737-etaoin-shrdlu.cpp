#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool compare(const pair<string,int> &a, const pair<string,int> &b) {
    if (a.second == b.second) {
        return lexicographical_compare(a.first.begin(), a.first.end(), b.first.begin(), b.first.end());
    }
    return a.second > b.second;
}

int main() {
    unordered_map<string,int> digrams;
    vector<pair<string,int>> freq;
    string input;
    string text;
    int n;

    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin.ignore();
        digrams.clear();
        freq.clear();

        text = "";
        for (int i = 0; i < n; i++) {
            getline(cin, input);
            text += input;
        }

        for (int i = 0; i < (text.size() - 1); i++) {
            string tok = text.substr(i, 2);
            auto item = digrams.find(tok);
            if (item == digrams.end()) {
                digrams.insert({tok, 1});
            } else {
                item->second++;
            }
        }

        for (auto kv : digrams) {
            freq.push_back(kv);
        }
        sort(freq.begin(), freq.end(), compare);

        cout.precision(6);
        cout << fixed;
        for (int i = 0; i < 5; i++) {
            cout << freq[i].first << " " << freq[i].second << " " << freq[i].second / double(text.size() - 1) << endl;
        }
        cout << endl;
    }

    return 0;
}
