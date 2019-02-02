#!/usr/bin/env python

import queue


class Graph:
    def __init__(self, n):
        self.distances = []
        self.edges = []
        for i in range(n):
            self.edges.append([])
        self.vertexes = n

    def add_edge(self, u, v, w):
        self.edges[u].append(Vertex(v, w))
        self.edges[v].append(Vertex(u, w))

    def diff(self):
        biggest = float("inf") * -1
        smallest = float("inf")
        for d in self.distances:
            if d > biggest:
                biggest = d
            if d != 0 and d < smallest:
                smallest = d
        return biggest - smallest

    def shortest_path(self, src):
        pq = queue.PriorityQueue()
        dist = [float("inf")] * self.vertexes
        pq.put(Vertex(src, 0))
        dist[src] = 0
        while not pq.empty():
            u = pq.get().vertex
            for e in self.edges[u]:
                v = e.vertex
                w = e.weight
                if (dist[v] > (dist[u] + w)):
                    dist[v] = dist[u] + w
                    pq.put(Vertex(v, dist[v]))
        self.distances = dist


class Vertex:
    def __init__(self, v, w):
        self.vertex = v
        self.weight = w

    def __lt__(self, other):
        return self.weight < other.weight

    def __repr__(self):
        return '{} {}'.format(self.vertex, self.weight)


def read_int():
    r = [int(i) for i in input().split()]
    if len(r) == 1:
        return int(r.pop())
    return r


if __name__ == '__main__':
    n, m = read_int()
    g = Graph(n)
    for i in range(m):
        u, v, p = read_int()
        g.add_edge(u - 1, v - 1, p)
    s = read_int()
    g.shortest_path(s - 1)
    print(g.diff())
