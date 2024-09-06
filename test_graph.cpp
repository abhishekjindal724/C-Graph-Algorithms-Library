#include "graph.h"
#include <iostream>
#include <vector>
#include <cassert>

// Helper function to print test case results
void reportTestResult(const std::string& testName, bool passed) {
    if (passed) {
        std::cout << "Test case passed: " << testName << std::endl;
    } else {
        std::cout << "Test case failed: " << testName << std::endl;
    }
}

// Test case for addEdge and hasEdge
void testAddEdge() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    g.addEdge(2, 3, 20);

    reportTestResult("testAddEdge - edge (0,1)", g.hasEdge(0, 1));
    reportTestResult("testAddEdge - edge (1,2)", g.hasEdge(1, 2));
    reportTestResult("testAddEdge - non-existent edge (2,0)", !g.hasEdge(2, 0));
}

// Test case for removeEdge
void testRemoveEdge() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    g.removeEdge(1, 2);

    reportTestResult("testRemoveEdge - removed edge (1,2)", !g.hasEdge(1, 2));
    reportTestResult("testRemoveEdge - edge (0,1) still exists", g.hasEdge(0, 1));
}

// Test BFS traversal
void testBFS() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(1, 3, 20);
    g.addEdge(2, 4, 25);

    std::cout << "BFS starting from node 0: ";
    g.BFS(0);  // Should print: 0 1 2 3 4 (depending on how the edges are added)
}

// Test DFS traversal
void testDFS() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(1, 3, 20);
    g.addEdge(2, 4, 25);

    std::cout << "DFS starting from node 0: ";
    g.DFS(0);  // Should print: 0 1 3 2 4 (depending on how the edges are added)
}

// Test Dijkstra's algorithm
void testDijkstra() {
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 5);
    g.addEdge(1, 4, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 7);

    std::vector<int> dist = g.dijkstra(0);
    bool correct = (dist[0] == 0 && dist[1] == 7 && dist[2] == 8 && dist[3] == 12 && dist[4] == 5);
    reportTestResult("testDijkstra - shortest path", correct);
}

// Test for detecting cycles in the graph
void testHasCycle() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 0, 1); // Creates a cycle
    g.addEdge(2, 3, 1);

    reportTestResult("testHasCycle - graph with cycle", g.hasCycle());

    // Create a graph without a cycle
    Graph g2(4);
    g2.addEdge(0, 1, 1);
    g2.addEdge(1, 2, 1);
    g2.addEdge(2, 3, 1);

    reportTestResult("testHasCycle - graph without cycle", !g2.hasCycle());
}

// Test graph printing
void testPrintGraph() {
    Graph g(3);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 15);
    std::cout << "Graph structure:\n";
    g.printGraph();
}

// Main function to run all tests
int main() {
    std::cout << "Running Graph Tests...\n";

    testAddEdge();
    testRemoveEdge();
    testBFS();
    testDFS();
    testDijkstra();
    testHasCycle();
    testPrintGraph();

    std::cout << "Testing completed." << std::endl;

    return 0;
}
