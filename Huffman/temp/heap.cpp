#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned ll
#define take(n) int n;cin>>n
#define mod 1000000007
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pp pop_back()
#define array(n,name) ll int *name=new ll int[n]
#define takearray(n,name) rep(i,0,n) cin>>name[i];
#define printarray(n,nums) rep(i,0,n) cout<<nums[i]<<" ";
#define nl cout<<endl;
using namespace std;

int xcor[4]={-1,0,0,+1};
int ycor[4]={0,-1,1,0};

ull int power(ull n,int x){
    if(x==0) return 1;
    return n * power(n,x-1);
}

class TreeNode{
    public:
    TreeNode *left;
    TreeNode *right;
    char val;
    int freq;
    TreeNode(char data,int frequency){
        val = data; 
        freq = frequency;
        left = NULL;
        right = NULL;
    }
};

class Compare{
    public:
    bool operator()(TreeNode *a,TreeNode *b){
        return a->freq>b->freq;
    }
};

class HuffmanCoding_heap{
    TreeNode *root;
    map<char,string> bitsTable;
    
    TreeNode* buildTree(vector<pair<char,int>> &freqTable,int n){
        priority_queue<TreeNode*,vector<TreeNode*>,Compare> pq;
        rep(i,0,n){
           TreeNode *newNode = new TreeNode(freqTable[i].first,freqTable[i].second);
           pq.push(newNode);
        }
        while(pq.size()>1){
            TreeNode *min1 = pq.top();
            pq.pop();
            TreeNode *min2 = pq.top();
            pq.pop();
            TreeNode *newNode = new TreeNode('*',min1->freq + min2->freq);
            newNode->left  = min1;
            newNode->right  = min2;
            pq.push(newNode);
        }
        return pq.top();
    }

    void dfs(TreeNode *current,string pattern=""){
        if(!current) return;
        if(current->left==NULL && current->right==NULL){
            bitsTable[current->val] = pattern;
            return;
        }
        dfs(current->left,pattern+'0');
        dfs(current->right,pattern+'1');
    }

    public:

    HuffmanCoding_heap(vector<pair<char,int>> &freqTable,int n){
        root = buildTree(freqTable,n);
        dfs(root);
    }
    void printCode(){
        cout<<"Bits Table encoded by Huffman coding is:-"<<endl;
        for(auto it:bitsTable){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    string encode(string input){
        string output = "";
        for(int i=0;i<input.length();i++){
            output+=bitsTable[input[i]];
        }
        return output;
    }
};


int main(){

    // Zubin Shah
    cout<<"Enter the number of entries in the freq Table: ";
    take(n);
    nl;
    vector<pair<char,int>> record;
    cout<<"Enter the character and corresponding avg percentage frequency line by line"<<endl;
    rep(i,0,n){
        char c;
        cin>>c;
        take(freq);
        record.pb(mp(c,freq));
    }
    HuffmanCoding_heap h(record,n);
    nl;
    h.printCode();
    nl;
    string input;
    cout<<"Enter the data to be sent: ";
    cin>>input;
    string encodedData = h.encode(input);
    cout<<"Encoded data: ";
    cout<<encodedData<<endl;
    


return 0;
}