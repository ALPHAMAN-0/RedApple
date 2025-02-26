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

int main() {
    pair<int,string> Pair;

    // We can use this way input pair
    Pair = make_pair(2,"ABC");
    Pair = {2,"ABC"};
    cout<<Pair.first <<" "<<Pair.second<<endl;
    
    //Copy Pair to pair
    pair<int,string> &p1 = Pair;
    p1.first = 3;
    cout<<Pair.first <<" "<<Pair.second<<endl;
    
    // Pair input
    pair<int,int> s;
    cin>>s.first>>s.second;
    cout<<s.first<<" "<<s.second<<endl;

    //Pair array
    pair<int,int> Pair_array[3];
    Pair_array[0] = {1,2};
    Pair_array[1] = {2,3};
    Pair_array[2] = {3,4};

    swap(Pair_array[0],Pair_array[2]);
    for(int i=0;i<3;i++){
        cout<<Pair_array[i].first<<" "<<Pair_array[i].second<<endl;
    }
    
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4); // O(1)
    v.push_back(5);
    
    swap(v[0],v[2]);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    //Vector all value 0 or a number like
    vector<int> v1(5,0);
    v1.push_back(1);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    //vector copy
    vector<int> v2(v1);   // O(N)
    v2.push_back(9);
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    //remove vector element
    v1.pop_back();
    for(int i=0;i<v1.size();i++){ 
        cout<<v1[i]<<" ";
    }


    return 0;
}
