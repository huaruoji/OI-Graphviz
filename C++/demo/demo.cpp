#include <bits/stdc++.h>
#include "..\src\graphviz.h"

using namespace std;
const int N=1e5+5;
int n;

int sz[N], ch[N][2], cnt[N], val[N], fa[N], rt, tot;
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
string key[15]={"","1","D","2","C","3","B","4","A","5"};
void dfs(int u) {
	if(lc(u)) {
		addEdge(key[u],key[lc(u)]);
		dfs(lc(u));
	}
	if(rc(u)) {
		addEdge(key[u],key[rc(u)]);
		dfs(rc(u));
	}
}

int outCnt;
void out() {
	fullClear();
	dfs(rt);
	graph::setDpi(300);
	graph::addStr("label=Splay"+to_string(++outCnt));
	autoOut("Splay"+to_string(outCnt));
}


inline void maintain(int x) {sz[x] = sz[lc(x)] + sz[rc(x)] + cnt[x];}
inline bool get(int x) {return x == rc(fa[x]);} //left child -> 0; right child -> 1;
inline void clear(int x) {lc(x) = rc(x) = sz[x] = fa[x] = val[x] = cnt[x] = 0;}
void rotate(int x) {
	int y = fa[x], z = fa[y], chk = get(x);
	ch[y][chk] = ch[x][chk^1]; if(ch[x][chk^1]) fa[ch[x][chk^1]] = y;
	ch[x][chk^1] = y; fa[y] = x;
	fa[x] = z; if(z) ch[z][y == ch[z][1]] = x;
	maintain(x); maintain(y); 
}
void splay(int x, int g = 0) {
	for(; fa[x] != g; rotate(x)) {
		out();
		if(fa[fa[x]] != g) {
			rotate(get(x) == get(fa[x]) ? fa[x] : x);
			out();
		}
	}
	if(g == 0) rt = x;
	out();
}
void insert(int k) {
	for(int u = rt, f = 0; ; f = u, u = ch[u][val[u] < k]) {
		if(val[u] == k ) {
			++cnt[u]; 
			maintain(u); maintain(f);
			splay(u);
			break;
		} else if(!u) {
			val[++tot] = k; ++cnt[tot];
			fa[tot] = f; if(f) ch[f][val[f] < k] = tot;
			maintain(tot); maintain(f);
			splay(tot);
			break;
		}
	}
} 
int rk(int k) {
	for(int res = 0, u = rt; ; ) {
		if(k < val [u]) u = lc(u);
		else {
			res += sz[lc(u)];
			if(k == val[u]) {
				splay(u);
				return res + 1;
			}
			res += cnt[u];
			u = rc(u);
		}
	}
}
int kth(int k) {
	for(int u = rt; ; ) {
		if(lc(u) && k <= sz[lc(u)]) u = lc(u);
		else {
			k -= cnt[u] + sz[lc(u)];
			if(k <= 0) {
				splay(u);
				return val[u];
			}
			u=rc(u);
		}
	}
}
int pre() {
	int u = lc(rt);
	while(rc(u)) u=rc(u);
	splay(u);
	return u;
}
int nxt() {
	int u=rc(rt);
	while(lc(u)) u=lc(u);
	splay(u);
	return u;
}
void del(int x) {
	rk(x);
	int u = rt;
	if(cnt[rt] > 1) {
		--cnt[rt]; maintain(rt);
	} else if(!lc(rt) && !rc(rt)) {
		clear(rt); rt=0;
	} else if(!lc(rt)) {
		rt = rc(rt); fa[rt] = 0;
		clear(u);
	} else if(!rc(rt)) {
		rt = lc(rt); fa[rt] = 0;
		clear(u);
	} else {
		int t = pre();
		fa[rc(u)] = t;
		rc(t) = rc(u);
		clear(u);	
		maintain(rt);
	}
}

int main() {
	for(int i=1;i<=9;i++) val[i]=i,cnt[i]=1;
	tot=9;
	lc(8)=6,rc(8)=9;
	lc(6)=4,rc(6)=7;
	lc(4)=2,rc(4)=5;
	lc(2)=1,rc(2)=3;
	sz[1]=sz[3]=sz[5]=sz[7]=sz[9]=1;
	maintain(2),maintain(4),maintain(6),maintain(8);
	fa[1]=fa[3]=2,fa[2]=fa[5]=4,fa[4]=fa[7]=6,fa[6]=fa[9]=8;
	rt=8;
	splay(2);
		
	return 0;
}
