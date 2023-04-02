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

#include "heap.cpp"
#include "twoQueues.cpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){

    srand(time(0));
    ofstream f;
    f.open("output/heap.dat");

    for(int i=30;i<60;i++){
        vector<pair<char,int>> record;
        for(int j=0;j<i;j++){
            char c = 'A' + j;
            int freq = 1+rand()%100;
            record.push_back(mp(c,freq));
        }
        
        auto start = high_resolution_clock::now();
        HuffmanCoding_heap h(record,i);
        auto stop = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop - start);
        ll int time1 = duration1.count();

        // start = high_resolution_clock::now();
        // HuffmanCoding_2Q h2(record,i);
        // stop = high_resolution_clock::now();
        // auto duration2 = duration_cast<microseconds>(stop - start);



        f<<i<<"\t"<<time1<<"\t"<<duration1.count()<<endl;
    }
    f.close();
    
    
    return 0;
}