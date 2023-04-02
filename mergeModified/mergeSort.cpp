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
void merge(vector<int> &nums,int left,int mid,int right){
    int
    vector<int> a;
    vector
}
void merge(vector<int> &nums,int left,int mid1,int mid,int mid2,int right){
    int sz1 = mid1-left+1;
    int sz2 = mid-mid1;
    int sz3 = mid2-mid+1;
    int sz4 = right-mid2;

    vector<int> a(mid1-left+1);
    vector<int> b(mid-mid1);
    vector<int> c(mid2-mid+1);
    vector<int> d(right-mid2);

    for(int i=left;i<=mid1;i++){
        a[i-left] = nums[i];
    }
    for(int i=mid1+1;i<=mid;i++){
        a[i-mid1-1] = nums[i];
    }
    for(int i=mid+1;i<=mid2;i++){
        a[i-mid] = nums[i];
    }
    for(int i=mid2+1;i<=right;i++){
        a[i-mid2-1] = nums[i];
    }

    int i = 0, j = 0, k = 0, l = 0;

    for(int x=left;x<=right;x++){
        
    }


}

void divideAndConquer(vector<int> &nums,int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        int mid1 = left + (mid-left)/2;
        int mid2 = mid+1 + (right-mid-1)/2;

        divideAndConquer(nums,left,mid1);
        divideAndConquer(nums,mid1+1,mid);
        divideAndConquer(nums,mid+1,mid2);
        divideAndConquer(nums,mid2+1,right);

        merge(nums,left,mid1,mid,mid2,right);
    }
}
void mergeSort(vector<int> &nums,int n){

}
int main(){

    Zubin Shah

    int n;
    cin>>n;
    vector<int> nums(n);
    rep(i,0,n) {
        cin>>nums[i];
    }

return 0;
}