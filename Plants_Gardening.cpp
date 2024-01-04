#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,cap;
    int count=0;
    cin>>n>>cap;
    int capacity=cap;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        if(a[i]<=cap){
            count++;
            cap-=a[i];
        }else{
            count+=i+i;
            cap=capacity;
            i--;
        }
    }
    cout<<count<<endl;
}