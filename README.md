# C-Graph-Algorithms-Library
A custom C++ Graph Library designed to implement various graph algorithms and data structures efficiently. This library supports advanced functionalities like Breadth-First Search (BFS), Depth-First Search (DFS), Dijkstra's shortest path algorithm, and cycle detection. Built with modularity and scalability in mind, the library leverages Boost for optimized data handling and integrates GoogleTest for automated testing of edge cases and ensuring reliability.

Key Features:
Graph Construction: Add, remove, and check edges in both directed and undirected graphs.

Graph Traversals: Efficient implementations of BFS and DFS for exploring graphs.

Shortest Path: Dijkstra's algorithm to compute the shortest path in weighted graphs.

Cycle Detection: Identify cycles in graphs using union-find with path compression.

Comprehensive Unit Testing: Includes detailed test cases for every algorithm using GoogleTest to guarantee accuracy and performance.

Cross-platform Compatibility: Configured with CMake, enabling easy integration into various development environments, including VS Code and MSYS.

Setup Instructions:
Clone the repository.
Use CMake to configure and build the library and tests.
Optionally, link this library to your own C++ projects for efficient graph manipulation and traversal.
Dependencies:
Boost (for advanced data handling)
GoogleTest (for unit testing)
CMake (for building the project)
This project is ideal for developers seeking an efficient and scalable solution for graph algorithms in their C++ projects.
