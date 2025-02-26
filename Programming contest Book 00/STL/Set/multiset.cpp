#include <iostream>
#include <vector>
#include<bitset>
#include<utility>
#include<algorithm>
#include <cstdint>
#include<set>
#include<unordered_map>
#include<unordered_set>

using namespace std;

#define vi vector<int> 
#define pii pair<int,int>
#define vipii vector<pii>
#define loop(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define SetBitsCount(x) __builtin_popcount(x)

void printer(multiset<string> s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
}
int main() {
    multiset<string> s;
    s.insert("hello");   //log(n)
    s.insert("world");
    s.insert("hello");
    printer(s);
     
    auto it = s.find("hello");
    //delete one element if same
    if(it!=s.end()){     // log(n)
        cout<<"Found"<<endl;
        cout<<(*it)<<endl;
        cout<<"Deleted"<<endl;
        s.erase(it);
    }
    //delete all element if same
    //s.erase("hello");
    cout<<"After Erase"<<endl;
    printer(s);

  
    return 0;
}
