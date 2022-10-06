// クラスカル法
// edges[cost,v,u]
// UnionFindが必要
class Kruskal {
  private:
    // n:頂点, m:辺の数
    int n;
    int m;
    long long sum_cost;
    using edge = tuple<long long, int, int>;
    vector<edge> edges;

  public:
    Kruskal(int n) : n(n) {}
    void add_edge(int v, int u, long long c) { edges.push_back({c, v, u}); }
    vector<int> minimum_spanning_tree() {
        // UnionFind木
        UnionFind uf(n);
        // sum_costを初期化
        sum_cost = 0;
        // 何番目の辺を採用したか
        vector<int> res;
        // コストの小さい順にソート
        sort(all(edges));
        m = (int)edges.size();
        rep(i, m) {
            auto [cost, v, u] = edges[i];
            // すでに採用していればダメ
            if(uf.same(v, u)) continue;
            // 採用
            uf.merge(v, u);
            res.push_back(i);
            sum_cost += cost;
        }
        return res;
    }
    // 最小全域木を作成する際に使用したコストの総和を返す
    long long get_sum_cost() { return sum_cost; }
};