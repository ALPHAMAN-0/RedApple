#include<iostream>
#include<vector>

using namespace std;

class graph{
    private:
        int V;
        vector<vector<int>> AdjacentList;
    public:
    graph(int vertices) {
        V = vertices;
        AdjacentList.resize(V);
    }
    void addEdge(int u, int v, bool directed) {
        AdjacentList[u].push_back(v);
        if (directed) {
            AdjacentList[v].push_back(u);
        }
    }
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int neighbor : AdjacentList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    bool detectCycle(bool directed ) {
        // We'll implement cycle detection for both directed and undirected graphs
        // For this example, we'll assume an undirected graph
        if(directed)
            return detectCycleDirected();
        else
        return detectCycleUndirected();
    }
    
    // Helper function for undirected cycle detection
    bool hasCycleUndirected(int v, vector<bool>& visited, int parent) {
        // Mark the current node as visited
        visited[v] = true;
        
        // Recur for all adjacent vertices
        for (int neighbor : AdjacentList[v]) {
            // If neighbor is not visited, check if subtree has a cycle
            if (!visited[neighbor]) {
                if (hasCycleUndirected(neighbor, visited, v))
                    return true;
            }
            // If neighbor is visited and not the parent, there is a cycle
            else if (neighbor != parent)
                return true;
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph
    bool detectCycleUndirected() {
        // Mark all vertices as not visited
        vector<bool> visited(V, false);
        
        // Call the helper function for each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (hasCycleUndirected(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
    
    // Helper function for directed cycle detection
    bool hasCycleDirected(int v, vector<bool>& visited, vector<bool>& recStack) {
        // Mark the current node as visited and add to recursion stack
        visited[v] = true;
        recStack[v] = true;
        
        // Recur for all adjacent vertices
        for (int neighbor : AdjacentList[v]) {
            // If not visited, check if there's a cycle in the subtree
            if (!visited[neighbor]) {
                if (hasCycleDirected(neighbor, visited, recStack))
                    return true;
            }
            // If the neighbor is in recursion stack, then there's a cycle
            else if (recStack[neighbor])
                return true;
        }
        
        // Remove the vertex from recursion stack
        recStack[v] = false;
        return false;
    }
    
    // Function to detect cycle in a directed graph
    bool detectCycleDirected() {
        // Mark all vertices as not visited and not part of recursion stack
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        // Call the helper function for each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (hasCycleDirected(i, visited, recStack))
                    return true;
            }
        }
        return false;
    }

};
