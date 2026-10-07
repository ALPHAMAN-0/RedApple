#include <iostream>
#include <vector>
#include<stack>

using namespace std;
const int N = 1e5+9;

bool Visited[N];
vector<int> Graph[N];

void FindConnectedComponents(int vertex){
        Visited[vertex] = true;
        for(int child: Graph[vertex]){
            if(Visited[child]) continue;
            FindConnectedComponents(child);
        }
}
int main() {
     int node,edge;
     cout<<"Enter Node and Edge"<<endl;
     cin>>node>>edge;
     // Graph[] and Visited[] have N slots, so every node number must be 0..N-1
     if(!cin || node<0 || node>=N){
        cout<<"Node numbers must be between 0 and "<<N-1<<endl;
        return 1;
     }
     
     int v1,v2;
     for(int i=0;i<edge;i++){
        cin>>v1>>v2;
        if(!cin || v1<0 || v1>=N || v2<0 || v2>=N){
            cout<<"Node numbers must be between 0 and "<<N-1<<endl;
            return 1;
        }
        Graph[v1].push_back(v2);
        Graph[v2].push_back(v1);
     }
     int ConnectComponentsCount = 0;
     for(int i=0;i<=node;i++){
        if(Visited[i]) continue;
        FindConnectedComponents(i);
        ConnectComponentsCount++;
     }

     cout<<"Connected Components of The graph is :" <<ConnectComponentsCount<<endl;
    return 0;
}
