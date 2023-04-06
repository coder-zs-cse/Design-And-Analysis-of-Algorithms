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

#include "dsfu.cpp"

int xcor[4]={-1,0,0,+1};
int ycor[4]={0,-1,1,0};

ull int power(ull n,int x){
    if(x==0) return 1;
    return n * power(n,x-1);
}

vector<vector<int>> MST_Kruskal(int V,int E,vector<vector<vector<int>>> &edges){ // Input do not have duplicate edges
    vector<vector<int>> msTree;
    vector<vector<int>> totalEdges;
    rep(i,1,V+1){
        rep(j,0,edges[i].size()){
            totalEdges.push_back({edges[i][j][1],edges[i][j][0],i});  // Cost Vertex1 Vertex2
        }
    }
    UnionFind dsfu(V); 
    sort(totalEdges.begin(),totalEdges.end()); // sorting according to cost
    int index = 0;
    rep(i,0,V-1){
        while(dsfu.checkCycle(totalEdges[index][1],totalEdges[index][2])){  //checking cycle exists or not through DSFU algo
            index++; //edges that form cycle are skipped
        }
        msTree.push_back({totalEdges[index][1],totalEdges[index][2],totalEdges[index][0]}); //Vertex1 vertex2 cost
        dsfu.addEdge(totalEdges[index][1],totalEdges[index][2]); // connecting the sets in DSFU
    }
    return msTree;

}
int costMST_Kruskal(int V,int E,vector<vector<vector<int>>> &edges){
    vector<vector<int>> mst = MST_Kruskal(V,E,edges);
    int cost = 0;
    cout<<"\nEdges in MST are:-\n";
    rep(i,0,V-1){
        cout<<mst[i][0]<<"-"<<mst[i][1]<<" "<<mst[i][2]<<endl;
        cost += mst[i][2];
    }
    return cost;
}

int main(){

    // Zubin Shah

    cout<<"Enter the number of Vertices: ";
    take(V);
    cout<<"Enter the number of Edges: ";
    take(E);
    cout<<"Enter the edges one by one in the format vertex1 vertex2 edgeCost\n";
    vector<vector<vector<int>>> edges(V+1);
    rep(i,0,E){
        take(a);
        take(b);
        take(c);
        edges[a].push_back({b,c});
    } 
    int MSTsum = costMST_Kruskal(V,E,edges);
    cout<<"Cost of mst = "<<MSTsum;

return 0;
}