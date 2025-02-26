#include <iostream>
#include <vector>
#include<bitset>
#include<utility>
#include<algorithm>
#include <cstdint>

using namespace std;

#define vi vector<int> 
#define pii pair<int,int>
#define vipii vector<pii>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define SetBitsCount(x) __builtin_popcount(x)

void printer(vector<int> &V) {
    cout<<"Size"<<V.size()<<endl;
    for(int i=0; i<V.size(); i++) {
        cout<<V[i]<<" ";
    }
    cout<<endl;
}
void inputer(vector<pair<int,int>> &V) {
    int n;
    cin>>n;
    loop(i,0,n) {
        int x,y;
        cin>>x>>y;
        V.push_back({x,y});
    }
}
int main() {
    //int this test case we have fixed row and colum means colum did not dynamically
    int n;
    cin>>n;
    vector<int> V[n];
    loop(i,0,n) {
        int m;
        cin>>m;
        loop(j,0,m) {
            int x;
            cin>>x;
            V[i].push_back(x);
        }
    }
    loop(i,0,n){
        printer(V[i]);
    }
    cout<< V[0][0]<<endl;

    //int this case we have row and colum dynamically
    int N;
    cin>>N;
    vector<vector<int>> V1;
    loop(i,0,N) {
        int m;
        cin>>m;
        vector<int>temp;
        loop(j,0,m) {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        V1.push_back(temp);
    }
    for(int i=0;i<V1.size();i++){
        printer(V1[i]);
    }

    return 0;
}
