#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> NextGreaterElement(vector<int> v){
    stack<int> s;
    vector<int> ans(v.size(),-1);
    for(int i=0;i<v.size();i++){
        while(!s.empty() && v[s.top()]<v[i]){
            ans[s.top()]=v[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

vector<int> NextSmallerElement(vector<int> v){
    stack<int> s;
    vector<int> ans(v.size(),-1);
    for(int i=0;i<v.size();i++){
        while(!s.empty() && v[s.top()]>v[i]){
            ans[s.top()]=v[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
int main(){
    int n;
    cout<<"1) Next Greater Element"<<endl;
    cout<<"2) Next Smaller Element"<<endl;
    cin>>n;
    cout<<"Enter the size of the array"<<endl;
    int size;
    cin>>size;
    vector<int> v(size);
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<size;i++){
        cin>>v[i];
    }
    vector<int> ans;
    switch(n){

        case 1:
            ans=NextGreaterElement(v);
            break;
        case 2:
            ans=NextSmallerElement(v);
            break;
    }
    printVector(ans);
    return 0;
    

}