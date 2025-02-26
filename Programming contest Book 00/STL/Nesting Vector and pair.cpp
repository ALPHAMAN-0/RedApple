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

void printer(vector<pair<int,int>> V) {
    for(int i=0; i<V.size(); i++) {
        cout<<V[i].ff<<" "<<V[i].ss<<endl;
    }
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

    vector<pair<int,int>> V = {{1,2},{2,3},{3,4},{4,5}};
    printer(V);

    inputer(V);
    printer(V);

        
    return 0;
}
