#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(a&&b || b&&c || c&&a)
          sum++;


    }
    cout<<sum<<endl;
    return 0;
}