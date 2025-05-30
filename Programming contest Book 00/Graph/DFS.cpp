#include <iostream>
#include<stack>
#include<vector>

using namespace std;

const int N = 1e5+9;

/* Example of graph
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/
vector<int> Graph[N];
bool Visited[N];
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

    void DfsRecoard(vector<bool> &visited,int s,vector<int> &record){
        visited[s] = true;
        record.push_back(s);
        for(int node : AdjacentList[s]) {
            if(!visited[node]) {
                DfsRecoard(visited, node, record);
            }
        }
    }
    vector<int> DFS(){
        vector<bool> visited(V,false);
        vector<int> record;
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DfsRecoard(visited, i, record);
            }
        }
        return record;
    }
};
void DFS(int vertex){
    //Part 1 : Take Action on vertex after entering the vertex
    cout<< vertex <<endl;
    
    Visited[vertex] = true;
    for(int child : Graph[vertex]){

        cout<<"Pair Node "<<vertex<<" Child "<<child<<endl;
        
        //Part 2 : Take Action on child before entering the child Node
        if(Visited[child])continue;
    
        DFS(child);

        //Part 3: Take Action on child after exiting ChildNode
    }
    //Part 4: Take Action on vertex Before Exiting The vertex

}
int main() {
	
    int vertex,edge;
    cout<<"Enter the Vertex and edge"<<endl;
    cin>>vertex>>edge;

    int V1,V2;
    for(int i=0; i<edge; i++){
        cin>>V1>>V2;

        Graph[V1].push_back(V2);
        Graph[V2].push_back(V1);

    }
    DFS(vertex);
    
    return 0;
}
