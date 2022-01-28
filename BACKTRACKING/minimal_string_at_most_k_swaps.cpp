void maxstring(string A, int B, string &temp){
    if(B==0){
        return;
    }
    for(int i=0;i<A.length()-1;i++){
        for(int j=i+1;j<A.length();j++){
            if(A[i]>A[j]){
                swap(A[i],A[j]);
                if(temp.compare(A)>0){
                    temp=A;
                }
                maxstring(A,B-1,temp);
                swap(A[i],A[j]);

            }
        }
    }
}



string Solution::solve(string A, int B) {
    string temp=A;
    maxstring(A,B,temp);
    return temp;
}
