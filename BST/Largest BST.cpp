



#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000


struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



Node* buildTree(string str) {
    
    if (str.length() == 0 || str[0] == 'N') return NULL;

    
    
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    
    Node* root = newNode(stoi(ip[0]));

    
    queue<Node*> queue;
    queue.push(root);

    
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        
        Node* currNode = queue.front();
        queue.pop();

        
        string currVal = ip[i];

        
        if (currVal != "N") {

            
            currNode->left = newNode(stoi(currVal));

            
            queue.push(currNode->left);
        }

        
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        
        if (currVal != "N") {

            
            currNode->right = newNode(stoi(currVal));

            
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 


struct info {
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

class Solution{
    
    public:
   
    
    info largestBSTinBT(Node* root){
        if(root==NULL) return {0, INT_MIN, INT_MAX, 0, true};
        if(root->right==NULL && root->left==NULL) return {1, root->data, root->data, 1, true};
        
        info leftinfo= largestBSTinBT(root->left);
        info rightinfo= largestBSTinBT(root->right);
        info curr;
        curr.size=(1+ leftinfo.size+rightinfo.size);
        if(leftinfo.isBST && rightinfo.isBST && root->data>leftinfo.max && root->data<rightinfo.min){
            curr.min= min(leftinfo.min, min(root->data, rightinfo.min));
            curr.max= max(rightinfo.max, max(root->data, leftinfo.max));
            
            curr.ans=curr.size;
            curr.isBST= true;
            return curr;
            
        }
        curr.ans=max(leftinfo.ans, rightinfo.ans);
        curr.isBST=false;
        return curr;
    }
    int largestBst(Node *root)
    {
    	
    	return largestBSTinBT(root).ans;
    }
};





  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  