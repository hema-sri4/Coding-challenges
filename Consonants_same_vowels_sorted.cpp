#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t="";
    cin>>s;
    int n=s.length();
    string ds="";    
    for(int i=0;i<n;i++){
        if(s[i]!='A' &&s[i]!='E'&&s[i]!='I'&&s[i]!='O' &&s[i]!='U'&&s[i]!='a' &&s[i]!='e'&&s[i]!='i'&&s[i]!='o' &&s[i]!='o'){
            t+=s[i];
        }else{
            ds+=s[i];
            t+='0';  
        }
    }
    sort(ds.begin(),ds.end());
    int j=0;
    for(int i=0;i<n;i++){
        if(t[i]=='0'){
            t[i]=ds[j++];
        }
    }
    cout<<t<<endl;
}