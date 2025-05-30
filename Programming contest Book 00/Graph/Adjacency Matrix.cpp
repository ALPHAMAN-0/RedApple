#include<iostream>
#include <vector>
using namespace std;
class Matrix{
    private:
        int V;
        vector<vector<int>> AdjacentMatrix;
    public:
    Matrix(int vertices) {
        V = vertices;
        AdjacentMatrix.resize(V, vector<int>(V, 0)); // Initialize with 0s
    }
    
    void addEdge(int u, int v, bool directed) {
        AdjacentMatrix[u][v] = 1; // Add edge from u to v
        if (!directed) {
            AdjacentMatrix[v][u] = 1; // Add edge from v to u for undirected graph
        }
    }
    
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Adjacency matrix row " << i << ": ";
            for (int j = 0; j < V; j++) {
                cout << AdjacentMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }  
};
