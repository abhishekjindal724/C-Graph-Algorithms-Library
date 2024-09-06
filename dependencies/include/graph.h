#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <climits>

class Graph {
public:
    Graph(int V);  // Constructor

    void addEdge(int v, int w, int weight = 1); // Add edge v-w with a weight
    void removeEdge(int v, int w); // Remove edge v-w
    bool hasEdge(int v, int w) const; // Check if edge exists

    void BFS(int start) const;  // Breadth First Search
    void DFS(int start) const;  // Depth First Search

    std::vector<int> dijkstra(int start) const; // Dijkstra's algorithm
    bool hasCycle() const;  // Check if graph has a cycle

    void printGraph() const;

private:
    int V; // Number of vertices
    std::list<std::pair<int, int>> *adj;  // Adjacency list: pair (vertex, weight)

    // Helper functions for graph algorithms
    int find(std::vector<int>& parent, int i) const; // Find the root of the set in union-find
    void unionSets(std::vector<int>& parent, std::vector<int>& rank, int x, int y) const; // Union by rank
};

#endif
