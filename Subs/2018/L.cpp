#include<bits/stdc++.h>
using namespace std;

struct node{
    int x;
    node(int _x=0):x(_x){}
	node operator+(const node& o){ // merge function
		return node(x+o.x);
	}
	bool operator!=(const node& o){
		return o.x != x;
	}
}nil(0),nada(-1);
 
struct SegmentTree{
	int n;
	vector<node>tree,lazy;
	SegmentTree(int _n=0):n(_n),tree(4*n,nil),lazy(4*n,nada){}

	void calc(node& a, const node& b, int len){
		a= node(b.x*len);
	}
    
	void push(int pos, int tl,int tr){ //assignment update, sum query
		if(lazy[pos]!=nada){
			int esq=2*pos, dir=2*pos+1;
			int mid = (tl+tr)/2;
			calc(tree[esq],lazy[pos],mid-tl+1);
			calc(tree[dir],lazy[pos],tr-(mid+1)+1);
		
			lazy[esq]=lazy[dir]=lazy[pos];
			lazy[pos]=nada;
		}
	}
	void update(int pos,int tl,int tr,int l, int r, node x){
		int esq=2*pos, dir=2*pos+1;
		int mid = (tl+tr)/2;
		if(tl>r || tr<l){
			return;
		}else if(tl>=l && tr<=r){
			calc(tree[pos],x,tr-tl+1);
			lazy[pos]=x;
		}else{
			push(pos,tl,tr);
			update(esq,tl,mid,l,r,x);
			update(dir,mid+1,tr,l,r,x);
 
			tree[pos]=tree[esq]+tree[dir];
		}
	}
 
	void update(int l, int r, node x){
		update(1,0,n-1,l,r, x);
	}
	node query(int pos, int tl, int tr, int l, int r){
		int esq=2*pos, dir=2*pos+1;
		int mid = (tl+tr)/2;
		if(tl>r || tr<l){
			return nil;//depends of the query type
		}else if(tl>=l && tr<=r){
			return tree[pos];
		}else{
			push(pos,tl,tr);
			return query(esq,tl,mid,l,r) + query(dir,mid+1,tr,l,r);
		}
	}
	node query(int l, int r){
		return query(1,0,n-1,l,r);
	}
};

vector<vector<int>> adj;
template<class T, class F>
struct HeavyLight{
	vector<int>pos,pai,h,sz;
	T tree;
	int timer;
	
	HeavyLight(int n, int root=0):pos(n),pai(n),h(n),sz(n),tree(n){	
		dfs(root);
		timer = 0;
		h[root]=root;
		buildHLD(root);
	}
	void dfs(int u, int p=-1){
		sz[u] = 1;
		for(int &v:adj[u]){
			if(v!=p){
				dfs(v,u);
				sz[u]+=sz[v];
				if(sz[v] > sz[adj[u][0]] || adj[u][0] == p)swap(v,adj[u][0]);
			}
		}
	}
	void buildHLD(int u, int p=-1){
		pos[u]=timer++;
		for(int v:adj[u]){
			if(v!=p){
				pai[v]=u;
				h[v] =(v==adj[u][0] ? h[u] : v);
				buildHLD(v,u);
			}
		}
	}
	F queryPath(int a ,int b){
		if(pos[a]<pos[b])swap(a,b);
 
		if(h[a]==h[b])return tree.query(pos[b],pos[a]);
 
		return tree.query(pos[h[a]],pos[a]) + queryPath(pai[h[a]],b);
	}
	void updatePath(int a, int b, F x){	
		if(pos[a]<pos[b])swap(a,b);
 
		if(h[a]==h[b]){
			tree.update(pos[b],pos[a],x);
			return;
		}
		tree.update(pos[h[a]],pos[a],x);
		updatePath(pai[h[a]],b,x);
	}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q;
	cin>>n>>q;
	adj.assign(n,{});
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
    HeavyLight<SegmentTree,node>hld(n);
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		--a;--b;--c;--d;
		hld.updatePath(a,b,node(1));
		int cnt2 = hld.queryPath(c,d).x;
		cout<<cnt2<<'\n';
		hld.updatePath(a,b,node(0));
	}
    return 0;
}