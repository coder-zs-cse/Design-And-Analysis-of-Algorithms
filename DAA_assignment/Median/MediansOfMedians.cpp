#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned ll
#define take(n) ll int n;cin>>n
#define mod 1000000007
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

int mediansOfMedians(vector<int> &nums,int n){
    vector<int> medians;
    for(int i=0;i<n;){
        int j = i;
        vector<int> temp;
        while(j<n && j-i+1<=5){
            temp.pb(nums[j]);
            j++;
        }
        i = j;
        sort(temp.begin(),temp.end());
        medians.pb(temp[2]);
    }
    sort(medians.begin(),medians.end());
    return medians[medians.size()/2];
}

int medianDivideAndConquer(vector<int> &nums,ll int n,ll int t=-1){
    if(t==-1) t=n/2;
    if(nums.size()==2) return max(nums[0],nums[1]);
    if(nums.size()==1) return nums[0];
    int pivot = mediansOfMedians(nums,n);
    vector<int> lower,upper;
    rep(i,0,n){
        if(nums[i]<pivot) lower.pb(nums[i]);
        else if(nums[i]>=pivot) upper.pb(nums[i]);
    }
    int k = lower.size();
    if(k==t) return pivot;
    if(k<t) return medianDivideAndConquer(upper,n-k,t-k);
    else return medianDivideAndConquer(lower,k,t);


}

int main(){

    Zubin Shah
    srand(time(0));
    take(n);
    vector<int> nums(n);
    rep(i,0,n) cin>>nums[i];
    int median = medianDivideAndConquer(nums,n);
    cout<<"Median is: "<<median;


return 0;
}