

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
