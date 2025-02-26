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
/*
   Question : Given N string and Q queries in each query you are given a string print
   yes if string is present else print no
*/
void printer(unordered_set<string> s) {
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
}
int main() {
    // Set work Red black tree
    // time complexity o(1)
    // space complexity o(n)
    int n;
    unordered_set<string> s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }
    int q;
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        if(s.find(str) != s.end())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
