// UnionFind
struct UnionFind {
    vector<int> par; // par[i] → root
    vector<int> siz;
    //コンストラクタ
    UnionFind(int N) : par(N), siz(N, 1) { rep(i, N) par[i] = i; }

    void init(int n) {
        siz.assign(n, 1);
        rep(i, n) par[i] = i;
    }

    // xの根を探索
    // 経路圧縮
    int root(int x) {
        if(par[x] == x) return x;
        return (par[x] = root(par[x]));
    }
    // xとyの木を併合
    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        // x>yの順にして小さいほうを大きいほうにくっつける(経路圧縮)
        if(siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }

    // 同じ木に属するかどうか
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    // xの属するグループの数
    int size(int x) {
        int rx = root(x);
        return siz[rx];
    }

    // 要素iまでの連結成分の個数 = Nで全体の連結成分の個数
    int component(int n) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(par[i] == i) res++;
        }
        return res;
    }
};
