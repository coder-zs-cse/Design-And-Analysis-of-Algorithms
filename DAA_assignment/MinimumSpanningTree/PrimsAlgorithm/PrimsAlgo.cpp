#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define ull unsigned ll
#define take(n) int n;cin>>n
#define mod 1000000007
#define pii pair<int,int>
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

// X is the set of vertices containing the tree during runtime of prims algorithm

vector<vector<int>> MST_Prims(int V,int E,vector<vector<vector<int>>> &edges){
    vector<vector<int>> msTree;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq ; 
    rep(i,0,edges[1].size()){
        pq.push({edges[1][i][1],edges[1][i][0],1}); //{cost neighourOf1 1}
    }
    vector<int> visited(V+1,0);
    visited[1] = 1; //Initialized X as {1}
    rep(i,1,V){
        while(visited[pq.top()[1]]){  
            pq.pop();  //pop away any internal edges
        }
        vector<int> current = pq.top(); // cost vertexOutsideX vertexInX
        pq.pop();
        msTree.push_back({current[1],current[2],current[0]}); // Add the edge into our final MST
        visited[current[1]] = 1; // add the new vertex into X

        rep(j,0,edges[current[1]].size()){
            int neighbour = edges[current[1]][j][0];
            if(!visited[neighbour]) // Add the neighbouring edges to Vertices which are not in X
                pq.push({edges[current[1]][j][1],neighbour,current[1]}); // cost VertexOutsideX vertexInX
        }
    } 
    return msTree;  
}

int costMST_Prims(int V,int E,vector<vector<vector<int>>> &edges){
    vector<vector<int>> mst= MST_Prims(V,E,edges);
    int sum = 0;
    cout<<"\nMST Edges are:-"<<endl;
    rep(i,0,mst.size()){
        cout<<mst[i][0]<<"-"<<mst[i][1]<<" "<<mst[i][2]<<endl;
        sum += mst[i][2];
    }
    return sum;
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
        edges[b].push_back({a,c});
    } 
    int MSTsum = costMST_Prims(V,E,edges);
    cout<<"Cost of mst = "<<MSTsum;

return 0;
}