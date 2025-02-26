#include <iostream>
#include <vector>
#include<bitset>
#include<utility>
#include<algorithm>
#include <cstdint>
#include<set>

using namespace std;

#define vi vector<int> 
#define pii pair<int,int>
#define vipii vector<pii>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define SetBitsCount(x) __builtin_popcount(x)

int main() {
     
    // when array sort then it will work O(logN) and it will not work for O(N)
    vector<int> V = {5,4,6,2,1};
    sort(V.begin(),V.end());

    for(int i=0; i<V.size(); i++) {
        cout<<V[i]<<endl;
    }
    
    cout<<"Lower Bound"<<endl;
    auto ptr = lower_bound(V.begin(),V.end(), 5);
    cout<<(*ptr)<<endl;

    cout<<"Upper Bound"<<endl;
    auto ptr1 = upper_bound(V.begin(),V.end(), 5);
    cout<<(*ptr1)<<endl;
 
    //when we use map and set Some Mistake 
    set<int> S={5,2,6,3,1,4};
 
    auto it = lower_bound(S.begin(),S.end(), 5);  //you can see rand function to see
    cout<<(*it)<<endl;              // it will work but time limite beacuse it will work O(N)
    
    // so thats why we use
    auto it1 = S.lower_bound(5);  // it will work O(logN)
    cout<<(*it1)<<endl;
    return 0;
}
