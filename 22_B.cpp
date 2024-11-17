#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int q;
    cin>>q;

    vector<int>v;
    while(q--){
        int x, a;
        cin >> x;
        if(x==1){
            cin>>a;
           v.push_back(a);
        }
        else if(x==2){
            v.erase(v.begin());
        }
        else if(x==3){
            cout<<v[0]<<endl;
        }
    } 
    return 0;
}