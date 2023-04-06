class UnionFind{
    int n;
    vector<int> rank;
    public:
    UnionFind(int num){
        n = num;
        rank = vector<int>(n+1);
        rep(i,0,n+1) rank[i] = i;
    }
    void addEdge(int a,int b){
        int rank1 = findRank(a);
        int rank2 = findRank(b);
        rank[rank1] = rank2;
    }
    bool checkCycle(int a,int b){
        if(findRank(a)==findRank(b)) return true;
        return false;
    }
    int findRank(int a){
        if(rank[a]!=a) return rank[a] = findRank(rank[a]);
        return a;
    }
};
