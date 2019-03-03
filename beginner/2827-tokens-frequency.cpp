#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string,int> tokens;
    string answer;
    string input;
    string tok;
    int max;
    int tmp;

    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    max = 0;
    for (int i = 0; i < (input.length() - 1); i++) {
        tok = input.substr(i, 2);
        auto item = tokens.find(tok);
        if (item == tokens.end()) {
            tmp = 1;
            tokens.insert({tok, tmp});
        } else {
            item->second++;
            tmp = item->second;
        }
        if (tmp > max) {
            max = tmp;
        }
    }

    answer = "";
    for (auto kv : tokens) {
        if (kv.second == max) {
            if (answer == "") {
                answer = kv.first;
            } else if (kv.first.compare(answer) < 0) {
                answer = kv.first;
            }
        }
    }
    cout << answer << ':' << max << endl;

    return 0;
}
