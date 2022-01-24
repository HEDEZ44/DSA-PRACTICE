// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        int count=0;
        int n=N;
        while(N!=0){
            N=N&(N-1);
            count++;
        }
        if(count>1 || count==0){
            return -1;
        }
        int i=0;
        while((n&(1<<i)) == 0){
            i++;
            
        }
        return i+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends