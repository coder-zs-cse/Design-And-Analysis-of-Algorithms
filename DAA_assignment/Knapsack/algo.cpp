#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned ll
#define take(n) int n;cin>>n
#define mod 1000000007
#define pii pair<int,int>
#define v(i) vector<i>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pp pop_back()
#define array(n,name) ll int *name=new ll int[n]
#define takearray(n,name) rep(i,0,n) cin>>name[i];
#define printarray(n,nums) rep(i,0,n) cout<<nums[i]<<" ";
#define Zubin ios::sync_with_stdio(false);
#define Shah cin.tie(NULL);cout.tie(0);
#define nl cout<<endl;
using namespace std;

int xcor[4]={-1,0,0,+1};
int ycor[4]={0,-1,1,0};

ull int power(ull n,int x){
    if(x==0) return 1;
    return n * power(n,x-1);
}

pair<vector<int>,int> knapsack(vector<int> weights,vector<int> values,int W){
    int n = weights.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    rep(i,1,n+1){
        rep(j,0,W+1){
            dp[i][j] = dp[i-1][j];
            if(weights[i-1]<=j) dp[i][j] = max(dp[i][j],dp[i-1][j-weights[i-1]] +values[i-1]);
        }
    }
    vector<int> output;
    int currentTotal = W;
    rrep(i,n,1){
        if(dp[i][currentTotal]!=dp[i-1][currentTotal]){
            currentTotal -= weights[i-1];
            output.pb(i-1);
        }
    }
    reverse(output.begin(),output.end());
    return mp(output,dp[n][W]);
}


int main(){

    // Zubin Shah
    cout<<"N: ";
    take(n);

    vector<int> weights(n);
    vector<int> values(n);
    cout<<"Weights: ";
    takearray(n,weights);
    cout<<"Values: ";
    takearray(n,values);
    cout<<"Capacity: ";
    take(capacity);
    nl;
    pair<vector<int>,int> steal = knapsack(weights,values,capacity);
    cout<<"Items selected: ";
    rep(i,0,steal.first.size()){
        cout<<steal.first[i]<<" ";
    }
    cout<<"\nTotal Value: "<<steal.second;



return 0;
}