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
        if (!directed) {
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

};
