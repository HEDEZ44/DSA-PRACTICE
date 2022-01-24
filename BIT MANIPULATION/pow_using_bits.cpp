#include<bits/stdc++.h>
using namespace std;

int power(int n){
    if(n==0){
        return 0;
    }
    if(n<0){
        n=-n;
    }

    int x=(n>>1);

    if(n&1){
        return ((power(x)<<2) + (x<<2) + 1) ; 
    }
    else{
        return (power(x)<<2);
    }
}

int main(){

    int n=5;

    cout<<power(n);



    return 0;
}