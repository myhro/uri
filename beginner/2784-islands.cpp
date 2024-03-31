#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// Compare swaps the comparison logic in order to sort std::priority_queue from min to max:
class Compare {
public:
    bool operator()(std::pair<int, int> a, std::pair<int,int> b) {
        return b.first < a.first;
    }
};

class Graph {
private:
    std::vector<std::vector<int>> data;

public:
    Graph(int size) : data(size, std::vector<int>(size)) {};

    std::vector<int>& operator[](int i) {
        return data[i];
    }

    std::vector<int> shortest_paths(int src) {
        auto distances = std::vector<int>(data.size(), INT_MAX);
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, Compare> pq;

        distances[src] = 0;
        pq.push(std::make_pair(0, src));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (unsigned int i = 0; i < data.size(); i++) {
                int v = i;
                int w = data[u][v];

                // No weight means no path or itself, skip this vertex:
                if (w == 0) {
                    continue;
                }

                int d = distances[u] + w;
                if (d < distances[v]) {
                    distances[v] = d;
                    pq.push(std::make_pair(d, v));
                }
            }
        }

        return distances;
    }
};

int main() {
    int n, m;
    int u, v, p;
    int s;

    std::cin >> n >> m;
    auto g = Graph(n);
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v >> p;
        u--;
        v--;
        g[u][v] = p;
        g[v][u] = p;
    }

    std::cin >> s;
    s--;
    auto distances = g.shortest_paths(s);

    int max = INT_MIN;
    int min = INT_MAX;
    for (unsigned int i = 0; i < distances.size(); i++) {
        int d = distances[i];
        if (d > max) {
            max = d;
        }
        if ((d != 0) && (d < min)) {
            min = d;
        }
    }

    std::cout << max - min << "\n";

    return 0;
}
