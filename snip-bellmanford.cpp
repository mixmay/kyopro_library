// ベルマンフォード法
// 負の距離を持つグラフの単一始点の最短経路を求める
// 負閉路があるか判定
class BellmanFord {
  private:
    struct edge {
        int from;
        int to;
        long long cost;
    };
    int v;
    vector<edge> edges;
    vector<long long> dist;
    const long long inf = 1LL << 60;

  public:
    // コンストラクタ
    BellmanFord(int n) : v(n), dist(n) { rep(i, n) dist[i] = inf; }
    // 辺の追加
    void add_edge(int v, int u, long long cost) {
        edges.push_back({v, u, cost});
    }
    // sからの最短経路を求める
    // trueであれば負閉路がある
    bool shortest_path(int s) {
        dist.resize(v, inf);
        dist[s] = 0;
        int cnt = 0;
        while(cnt < v) {
            bool update = false;
            for(auto e : edges) {
                if(dist[e.from] != inf && dist[e.from] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[e.from] + e.cost;
                    update = true;
                }
            }
            if(!update) break;
            cnt++;
        }
        return (cnt == v);
    }

    vector<long long> get_shortest_path() { return dist; }
};
