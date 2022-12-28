// ダイクストラ法
// 単一始点の最短経路の距離を求める
// 単一始点の最短経路のパスを求める
// 最短路木を作る際に採用した辺を求める
class Dijkstra {
  private:
    // 辺の構造体
    struct edge {
        // to->iから隣接している頂点,index->辺のindex, cost->辺の重み
        int to;
        // 辺の頂点のコスト
        long long cost;
        // 辺のindex
        int index;
        edge(int to, long long cost, int index)
            : to(to), cost(cost), index(index) {}
    };
    // 始点
    int s;
    //グラフの定義
    vector<vector<edge>> graph;
    // dist[i] -> sからiまでの距離
    vector<long long> dist;
    // from[i] -> sからiの最短経路に採用した辺のindex
    vector<int> from;
    //　辺の集合
    vector<pair<int, int>> edges;
    // 最短路木を作るための辺のindexの集合
    vector<int> shortest_path_edges;
    // [dist,now,edge_index]
    using dnp = tuple<long long, int, int>;
    long long inf = 1e18 + 1;

  public:
    Dijkstra(long long n) : graph(n), dist(n), from(n) {
        rep(i, n) dist[i] = inf;
        rep(i, n) from[i] = -1;
    }
    //辺の追加
    void add_edge(int v, int u, long long cost, int index) {
        edge e(u, cost, index);
        // グラフに辺を追加
        graph[v].push_back(e);
        // 辺の情報を配列でもっておく
        // 無向グラフの場合は一度のみ追加
        if(index == (int)edges.size()) edges.emplace_back(v, u);
    }

    // sを始点に最短経路を求める
    void shortest_path(int s) {
        //小さい順のpriority_queue
        //[dist,now, edge_index]
        priority_queue<dnp, vector<dnp>, greater<dnp>> mpq;
        int n = (int)graph.size();
        // sからのdist,fromを初期化
        dist.resize(n, inf);
        from.resize(n, -1);
        // その頂点が始点なのか到達不可能なのか区別するためにindexを-2で更新
        mpq.push({0, s, -2});

        // 距離が近い順に探索
        while((int)mpq.size()) {
            // [dist,v,edge_index]
            auto [d, v, ei] = mpq.top();
            mpq.pop();
            if(dist[v] <= d) continue;
            dist[v] = d;
            from[v] = ei;
            if(ei >= 0) shortest_path_edges.push_back(ei);
            // 隣隣接している頂点を見る
            // [to,cost,index]
            for(auto [u, c, i] : graph[v]) {
                // 探索済みならスルー
                if(dist[u] <= d + c) continue;
                // vまでの距離と辺のコストが距離となる
                mpq.emplace(d + c, u, i);
            }
        }
    }

    // 頂点xまでの最短経路の距離を取得
    long long get_dist(int x) { return dist[x]; }

    // 最短路木を作る際に採用する辺を求める
    vector<int> get_shortest_path_edges() { return shortest_path_edges; }

    // 頂点xまでの最短経路が存在するか
    bool is_shortest_path(int x) {
        if(dist[x] != inf)
            return true;
        else
            return false;
    }
    // 頂点sから頂点xにおける最短経路
    // [index,v,u]
    vector<tuple<int, int, int>> get_shortest_path(int x) {
        vector<tuple<int, int, int>> res;
        // その頂点には到達不可能
        if(from[x] == -1) {
            res.push_back({-1, -1, -1});
            return res;
        }
        // その頂点はスタート
        if(from[x] == -2) {
            res.push_back({-1, -1, -1});
            return res;
        }

        //根に戻るまで探索
        while(from[x] >= 0) {
            auto [v, u] = edges[from[x]];
            res.push_back({x, v, u});
            x = v;
        }
        return res;
    }
};