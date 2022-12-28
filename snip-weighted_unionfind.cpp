// 重み付き(ポテンシャル)UnionFind
template <typename T> struct WeightedUnionFind {
    int n;           // 頂点の数
    vector<int> par; // par[i] → root
    vector<int> siz; // UnionFind木のroot[i]の部分木のサイズ
    vector<T> pot;   // ポテンシャル
    // コンストラクタ
    // tは初期値
    WeightedUnionFind(int n, T t) : n(n), par(n), siz(n), pot(n) { init(n, t); }

    void init(int n, T t) {
        rep(i, n) par[i] = i;
        rep(i, n) siz[i] = 1;
        rep(i, n) pot[i] = t;
    }

    // xの根を探索
    int root(int x) {
        if(par[x] == x)
            return x;
        else {
            //経路圧縮
            int r = root(par[x]);
            pot[x] += pot[par[x]];
            return (par[x] = r);
        }
    }
    // xとyの木を併合,ポテンシャルも計算
    void merge(int x, int y, int z) {
        int rx = root(x);
        int ry = root(y);
        //ポテンシャルをすでに計算している場合スルー
        if(rx == ry) return;
        // x,rx間とy,ry間とry,rx間のポテンシャルの計算
        // 根から葉に行く(落ちる)時は-,逆に進む場合は+
        // y-xなので y→ry→rx→x = z
        // 移行してry→rx = z + rx→x - y→ry
        z += pot[x] - pot[y];
        // x>yの順にして小さいほうを大きいほうにくっつける(union by size)
        if(siz[rx] < siz[ry]) swap(rx, ry), swap(x, y), z *= -1;
        siz[rx] += siz[ry];
        par[ry] = rx;
        pot[ry] = z;
    }

    // y-xを求める
    T diff(int x, int y) { return (pot[y] - pot[x]); }

    //同じ木に属するかどうか
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
};