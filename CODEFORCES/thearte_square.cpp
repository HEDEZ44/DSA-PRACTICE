#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a;
    cin>>n>>m>>a;
    int count1=0;
    int count2=0;
    while(n>0){
        n-=a;
        count1++;
    }
    while(m>0){
        m-=a;
        count2++;
    }
   
    int needed=count1*count1;
    cout<<needed<<endl;
    
    return 0;
}