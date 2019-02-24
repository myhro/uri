#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string,int> tokens;
    int max;
    string input;
    string tok;

    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    max = 0;
    for (int i = 0; i < (input.length() - 1); i++) {
        tok = input.substr(i, 2);
        if (tokens.count(tok) == 0) {
            tokens[tok] = 1;
        } else {
            tokens[tok]++;
        }
        if (tokens[tok] > max) {
            max = tokens[tok];
        }
    }

    for (auto kv : tokens) {
        if (kv.second == max) {
            cout << kv.first << ':' << kv.second << endl;
            break;
        }
    }

    return 0;
}
