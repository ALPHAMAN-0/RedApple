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
    vector<int> V  = {1,2,3,4,5};
    for(int i=0; i<V.size(); i++) {
        cout<<V[i]<<endl;
    }
    //it+1 dose not work maps and sets but work it++
    vector<int> :: iterator it;
    for(it=V.begin(); it!=V.end(); it++) {
        cout<<*it<<endl;
    }
    vector<pair<int,int>> v1={{1,2},{2,3},{3,4},{4,5}};
    vector<pair<int,int>> :: iterator it1;
    for(it1=v1.begin(); it1!=v1.end(); it1++) {
        cout<<it1->ff<<" "<<it1->ss<<endl;
    }       
    
    //Iterator in short
    //Range base when we use &real value come and you can change the value 
    //when we use value it store copy value
    for(int &value: V){
        cout<<value<<endl;
    }
    //auto
    //auto variable detacted by compiler
    // auto a = 1.1 or auto a = 1 auto detected by compiler
    for(auto value: V){
        cout<<value<<endl;
    }
    for(auto it2=V.begin(); it2!=V.end(); it2++) {
        cout<<*it2<<endl;
    }
    for(pair<int,int> value: v1){ //but when we use auto then you can not use pair<int,int> it will detect auto
        cout<<value.ff<<" "<<value.ss<<endl;
    }

    return 0;
}
