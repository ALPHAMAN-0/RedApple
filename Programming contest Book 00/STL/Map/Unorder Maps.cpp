#include <iostream>
#include <vector>
#include<bitset>
#include<utility>
#include<algorithm>
#include <cstdint>
#include<set>
#include<unordered_map>

using namespace std;

#define vi vector<int> 
#define pii pair<int,int>
#define vipii vector<pii>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define SetBitsCount(x) __builtin_popcount(x)

void Printer(unordered_map<int,string> &Maping){

    for(auto it = Maping.begin(); it!=Maping.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}
int main() {
    // Map work Red black tree
    unordered_map<int,string> Maping;
    Maping[0] = "ABC";     // O(log(n))
    Maping[1] = "DEF";
    Maping[2] = "GHI";

    Maping.insert({3,"JKL"}); // O(log(n))

    // map<string,string> Maping s.size() * log(n)
    Printer(Maping);

    auto it = Maping.find(3); // O(log(n)
    //want to find a value in the map
    if(it==Maping.end()){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<it->first<<" "<<it->second<<endl;
    }

    //want to delete value from the map
    Maping.erase(3);   //logN
    Printer(Maping);    

    return 0;
}
