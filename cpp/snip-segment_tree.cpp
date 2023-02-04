// セグメント木 1-indexed
// 一点更新、区間取得
template <typename T> class SegmentTree {
  private:
    using F = function<T(T, T)>;

    int n;         // 配列の要素数(!=datの要素数)
    vector<T> dat; // セグメント木
    F combine;     // 区間に対する演算
    T identity;    // 単位元

    void init() {
        // すべての要素を単位元で初期化
        dat.resize(n << 2, identity);
    }

  public:
    SegmentTree(int n, F combine, T identity)
        : n(n), combine(combine), identity(identity) {
        init();
    }

    //一点更新(iをxで更新)
    void set(int i, T x) {
        i += n;
        // 加算などdat[i]に対して処理する場合は記述
        // (例)dat[i] = dat[i] + x;
        dat[i] = x;
        while(true) {
            i /= 2;
            if(i == 0) break;
            dat[i] = combine(dat[i * 2], dat[i * 2 + 1]);
        }
    }

    // 区間取得[l,r)
    T fold(int l, int r) {
        T res = identity;
        l += n;
        r += n;
        while(l < r) {
            if(l % 2) res = combine(res, dat[l++]);
            if(r % 2) res = combine(res, dat[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};
