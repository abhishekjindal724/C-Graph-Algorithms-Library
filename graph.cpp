#include "graph.h"
#include <set>  // Include the set header for std::set
#include <limits.h>  // For INT_MAX

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<std::pair<int, int>>[V];
}

void Graph::addEdge(int v, int w, int weight) {
    if (v < V && w < V) {
        adj[v].push_back(std::make_pair(w, weight));
        adj[w].push_back(std::make_pair(v, weight)); // For undirected graph
    }
}

void Graph::removeEdge(int v, int w) {
    if (v < V && w < V) {
        adj[v].remove_if([w](const std::pair<int, int>& edge){ return edge.first == w; });
        adj[w].remove_if([v](const std::pair<int, int>& edge){ return edge.first == v; });
    }
}

bool Graph::hasEdge(int v, int w) const {
    if (v < V && w < V) {
        for (auto& edge : adj[v]) {
            if (edge.first == w) return true;
        }
    }
    return false;
}

void Graph::BFS(int start) const {
    if (start >= V) return; // Handle out of bounds

    std::vector<bool> visited(V, false);
    std::list<int> queue;
    visited[start] = true;
    queue.push_back(start);

    while (!queue.empty()) {
        int node = queue.front();
        std::cout << node << " ";
        queue.pop_front();

        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push_back(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::DFS(int start) const {
    if (start >= V) return; // Handle out of bounds

    std::vector<bool> visited(V, false);
    std::list<int> stack;
    stack.push_back(start);

    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();

        if (!visited[node]) {
            visited[node] = true;
            std::cout << node << " ";
        }

        for (auto& edge : adj[node]) {
            int neighbor = edge.first;
            if (!visited[neighbor]) {
                stack.push_back(neighbor);
            }
        }
    }
    std::cout << std::endl;
}

std::vector<int> Graph::dijkstra(int start) const {
    std::vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    // Declare the setds properly as a set of pairs
    std::set<std::pair<int, int>> setds;  // (distance, vertex)

    setds.insert(std::make_pair(0, start));

    while (!setds.empty()) {
        int u = setds.begin()->second;
        setds.erase(setds.begin());

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                if (dist[v] != INT_MAX) {
                    setds.erase(setds.find(std::make_pair(dist[v], v)));
                }
                dist[v] = dist[u] + weight;
                setds.insert(std::make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int Graph::find(std::vector<int>& parent, int i) const {
    if (parent[i] == i) return i;
    return parent[i] = find(parent, parent[parent[i]]);
}

void Graph::unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) const {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

bool Graph::hasCycle() const {
    std::vector<int> parent(V);
    std::vector<int> rank(V, 0);

    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    for (int u = 0; u < V; ++u) {
        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (u < v) {  // Only process one direction for undirected graph
                int uSet = find(parent, u);
                int vSet = find(parent, v);

                if (uSet == vSet) {
                    return true;
                }
                unionSets(parent, rank, uSet, vSet);
            }
        }
    }
    return false;
}

void Graph::printGraph() const {
    for (int v = 0; v < V; ++v) {
        std::cout << "Adjacency list of vertex " << v << ":\n";
        for (auto& edge : adj[v]) {
            std::cout << " -> " << edge.first << " (weight " << edge.second << ")";
        }
        std::cout << std::endl;
    }
}
