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
int count(vector<int> arr,int n,int key){
    int firstIndex = -1;
    int left = 0, right = n-1;
    while(left<right){
        int mid = left + (right-left)/2;
        if(arr[mid]<key){
            left = mid +1;
        }
        else if(arr[mid]>key){
            right = mid-1;
        }
        else{
            right  = mid;
        }
    }
    firstIndex = arr[left] == key ? left : -1;
    if(firstIndex==-1) return 0;
    left = 0;
    right  = n-1;
    int lastIndex = -1;
    while(left<right){
        int mid = left + (right-left+1)/2;
        if(arr[mid]<key){
            left = mid +1;
        }
        else if(arr[mid]>key){
            right = mid-1;
        }
        else{
            left  = mid;
        }
    }
    lastIndex = arr[left] == key ? left : -1;
    return  lastIndex - firstIndex + 1;
}
int main(){

    Zubin Shah

    vector<int> arr(10);
    rep(i,0,10){
        arr[i] = rand()%5;
    }
    sort(arr.begin(),arr.end());
    rep(i,0,10) cout<<arr[i]<<" ";
    nl;
    cout<<count(arr,arr.size(),5);

return 0;
}