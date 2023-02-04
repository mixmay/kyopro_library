// 双対セグメント木 1-indexed
// 区間更新、一点取得
// 可換
template <typename T> class DualSegmentTree {
  private:
    using F = function<T(T, T)>;

    int n;            // 配列の要素数(!=datの要素数)
    vector<T> dat;    // セグメント木
    vector<int> time; // i番目の作用後の値を記録
    F combine;        // 区間に対する演算
    T identity;       // 単位元

    void init() {
        // すべての要素を単位元で初期化
        dat.resize(n << 2, identity);
    }

  public:
    DualSegmentTree(int n, F combine, T identity)
        : n(n), combine(combine), identity(identity) {
        init();
    }

    //一点取得
    T get(int i) {
        i += n;
        // 加算などdat[i]に対して処理する場合は記述
        // (例)dat[i] = dat[i] + x;
        T res = dat[i];
        while(true) {
            i /= 2;
            if(i == 0) break;
            res = combine(res, dat[i]);
        }
        return res;
    }

    // i番目の区間更新[l,r)に対してxの演算を行う
    void fold(int l, int r, int x) {
        l += n;
        r += n;
        while(l < r) {
            if(l % 2) dat[l] = combine(dat[l], x), l++;
            if(r % 2) dat[r - 1] = combine(dat[r - 1], x), r--;
            l /= 2;
            r /= 2;
        }
    }
};
