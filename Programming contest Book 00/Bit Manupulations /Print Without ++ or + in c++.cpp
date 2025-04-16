#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
void printer(int n){
    int i=1;
    for(;i<=n;){
        cout<<i<<" ";
        i = -~i;
    }
}
