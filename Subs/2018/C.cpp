#include<bits/stdc++.h>
using namespace std;
template<class T>
struct CoordinateCompression{
    vector<T>v;
    void push(const T &a){v.push_back(a);}
    int build(){
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        return (int)v.size();
    }
    int operator[](const T &a){
        auto it=lower_bound(v.begin(),v.end(),a);
        return int(it - v.begin());
    }
};
template<class T>
struct BIT{
    int n;
    vector<T>bit;
    BIT(int n_=0):n(n_),bit(n+1){} //1-based
    void update(int x, T val){
        for(;x<=n;x+=(x&-x))bit[x]+=val;
    }
    T query(int x){ //query on [1,r]
        T ret=0;
        for(;x>0;x-=(x&-x))ret+=bit[x];
        return ret;
    }
    T query(int l, int r){ //query on [l,r]
		if(r < l)return 0;
        return query(r)-query(l-1);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    CoordinateCompression<int>mpx,mpy;
	int x,y;
	cin>>x>>y;
	mpx.push(0);mpy.push(0);
	mpx.push(x);mpy.push(y);

	int h,v;	
	cin>>h>>v;
	vector<pair<int,int>>hori(h);
	vector<pair<int,int>>verti(v);
	for(auto &[y1,y2] : hori){
		cin>>y1>>y2;
		mpy.push(y2);
	}
	for(auto &[x1,x2] : verti){
		cin>>x1>>x2;
		mpx.push(x2);
	}
	sort(begin(hori),end(hori));
	sort(begin(verti),end(verti));
	long long ans = 1;
	{
		int len = mpy.build() + 1;
		BIT<int>edson(len + 1);
		for(int i=0;i<h;++i){
			int y2 = hori[i].second;
			y2 = mpy[y2];
			ans += edson.query(y2 + 1, len) + 1;
			edson.update(y2, 1);
		}
	}
	{
		int len = mpx.build() + 1;
		BIT<int>leo(len + 1);
		for(int i=0;i<v;++i){
			int x2 = verti[i].second;
			x2 = mpx[x2];
			ans += leo.query(x2 + 1, len) + h + 1;
			leo.update(x2, 1);
		}
	}
	cout<<ans<<'\n';
    return 0;
}