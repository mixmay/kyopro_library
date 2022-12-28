// DAG
// トポロジカルソート
// 最長経路の長さ、経路、パス
// おまけでDAGかどうか(有向グラフに閉路があるか)判定
struct DAG {
    // グラフ
    vector<vector<int>> g;
    // グラフがDAGかどうか
    bool dag;
    // トポロジカルソートを行ったかどうか
    bool sorted;
    // indegree[i]における入次数の数
    vector<int> indegree;
    // outdegree[i]における出次数の数
    vector<int> outdegree;
    // トポロジカルソート済みリスト
    vector<int> topo_sorted_list;
    // 頂点iまでの最長経路の長さ
    vector<int> maxdist;
    // DAG上の最長パス
    vector<int> longestpath;
    // 最長パスを求める際のパス上の親
    vector<int> from;

    DAG(int n) : g(n), indegree(n), outdegree(n), maxdist(n), from(n) {
        rep(i, n) from[i] = i;
        dag = true;
        sorted = false;
    }

    // グラフの作成
    void make_edge(int v, int u) {
        // vからuを辺で結ぶ
        g[v].push_back(u);

        // 入次数と出次数を記録
        indegree[u]++;
        outdegree[v]++;
    }

    // グラフに閉路があるかどうかを調べる
    bool is_dag() {
        // トポロジカルソートができればDAG,できなければ非DAGといえる
        // トポロジカルソートをしていなかったらする
        if(!sorted) topological_sort();
        if(dag)
            return true;
        else
            return false;
    }

    // トポロジカルソート
    void topological_sort() {
        sorted = true;
        // indegreeをコピーする
        vector<int> cp_indegree = indegree;
        // 入次数がない頂点を探索する
        vector<int> li;
        vector<bool> used((int)g.size());
        rep(i, (int)cp_indegree.size()) {
            int v = cp_indegree[i];
            if(!v) li.push_back(i);
        }

        // 入次数0の頂点を消してDAGを小さくしていくことで、頂点の最大のパスの長さで緩和できる(DP)
        for(int i = 0; i < (int)li.size(); i++) {
            int v = li[i];
            used[v] = true;
            // 入次数のない頂点を配列に格納
            topo_sorted_list.push_back(v);
            for(auto u : g[v]) {
                // vの出次数=uの入次数を消す
                cp_indegree[u]--;
                // 入次数が0ならばリストに追加
                if(!cp_indegree[u]) {
                    li.push_back(u);
                    // 最長経路で緩和
                    // 行き先が今のパスで緩和できる場合,親を記録
                    if(maxdist[u] < maxdist[v] + 1) {
                        maxdist[u] = maxdist[v] + 1;
                        from[u] = v;
                    }
                }
            }
        }

        // ソートが終わった際、すべての頂点を見ていればDAG、そうでないなら非DAG
        for(auto v : used)
            if(!v) dag = false;
    }

    //最長パスを取得する
    vector<int> get_longest_path() {
        vector<int> res;
        // 最長パスの長さの末尾からfromを辿っていく
        // スタートの位置を求める
        int v = max_element(all(maxdist)) - maxdist.begin();
        while(from[v] != v) {
            res.push_back(v);
            v = from[v];
        }
        res.push_back(v);
        reverse(all(res));
        return res;
    }

    //最長経路の長さを取得する
    int get_longestpath_dist() { return *max_element(all(maxdist)); }

    //--------------------------------------------------------------------------
    // debug
    //--------------------------------------------------------------------------

    // トポロジカルソートした順序を出力
    void show_topo_sorted_list() {
        for(auto v : topo_sorted_list) cout << v << " ";
        cout << endl;
    }

    // 最長パスを出力
    void show_longestpath() {
        auto path = get_longest_path();
        for(auto v : path) cout << v << " ";
        cout << endl;
    }
};