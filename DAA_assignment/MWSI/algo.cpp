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

vector<int> MWIS(vector<int> &nums,int n){
    vector<int> dp(n+1,0);
    dp[1] = nums[0];
    rep(i,2,n+1){
        dp[i] = max(dp[i-1],dp[i-2] + nums[i-1]);
    }
    vector<int> output;
    rrep(i,n,1){
        if(i==1 || dp[i-1]<dp[i-2]+nums[i-1]){
            output.push_back(nums[i-1]);
            i--;
        }
    }
    reverse(output.begin(),output.end());
    return output;
}

int main(){

    Zubin Shah
    take(n);
    vector<int> nums(n);
    takearray(n,nums);
    vector<int> mwis = MWIS(nums,n);
    for(auto it:mwis){
        cout<<it<<" ";
    }
    nl;
    

return 0;
}