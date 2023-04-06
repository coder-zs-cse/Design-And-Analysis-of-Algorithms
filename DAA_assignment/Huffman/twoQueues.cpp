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

bool compare(pair<char,int> a,pair<char,int> b){
    return a.second < b.second;
}

TreeNode* chooseMinimum(queue<TreeNode*> &q1,queue<TreeNode*> &q2){
    TreeNode *temp;
    if(q1.empty()) {
        temp = q2.front();
        q2.pop();
    }
    else if(q2.empty()) {
        temp = q1.front();
        q1.pop();
    }
    else{
        if(q1.front()->freq < q2.front()->freq){
            temp = q1.front();
            q1.pop();
        }
        else{
            temp = q2.front();
            q2.pop();
        }
    }
    return temp;
}
class HuffmanCoding_2Q{
    TreeNode *root;
    map<char,string> bitsTable;
    double avgBits;
    
    TreeNode* buildTree(vector<pair<char,int>> &freqTable,int n){
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        sort(freqTable.begin(),freqTable.end(),compare);
        for(int i=0;i<n;i++){
            TreeNode *newnode = new TreeNode(freqTable[i].first,freqTable[i].second);
            q1.push(newnode);
        }

        while(q1.size() + q2.size()>1){
            TreeNode *min1 = chooseMinimum(q1,q2);
            TreeNode *min2 = chooseMinimum(q1,q2);
            TreeNode *newnode = new TreeNode('*',min1->freq + min2->freq);
            newnode->left = min1;
            newnode->right = min2;
            q2.push(newnode);
        }
        return q2.front();
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

    HuffmanCoding_2Q(vector<pair<char,int>> &freqTable,int n){
        root = buildTree(freqTable,n);
        //generateBitsTable
        dfs(root);
        avgBits = calcAvgBits();
        
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
    double calcAvgBits(){
        double sum = 0;
        for(auto it:bitsTable){
            sum+= (double)it.second.length();
        }
        return sum/bitsTable.size();
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
    HuffmanCoding_2Q h(record,n);
    nl;
    h.printCode();
    nl;
    string input;
    cout<<"Enter the data to be sent: ";
    cin>>input;
    string encodedData = h.encode(input);
    cout<<"Encoded data: ";
    cout<<encodedData<<endl;

    nl;
    cout<<"Average Bits required in encoding process: "<<h.calcAvgBits();
    


return 0;
}