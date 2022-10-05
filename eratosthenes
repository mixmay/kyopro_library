//エラトステネスの篩を利用した
//素数判定
//素因数分解、列挙
//約数列挙
struct Eratosthenes {
    // IsPrime[i]が素数かどうか
    vector<bool> is_prime;
    // minfactor[i]の約数の最小の素数
    vector<int> minfactor;
    // primefactor[i]の<素因数,指数>の列挙
    vector<vector<pair<int, int>>> primefactor;

    Eratosthenes(int n)
        : is_prime(n + 1, true), minfactor(n + 1, -1), primefactor(n + 1) {
        // 0,1に関する初期化
        is_prime[0] = is_prime[1] = false;
        minfactor[1] = 1;

        //篩
        for(int i = 2; i <= n; i++) {

            //古いに落とされたものはスキップ
            if(!is_prime[i]) continue;

            //素数の場合は必ずiが最小の約数での素数となる
            minfactor[i] = i;

            for(int j = 2; i * j <= n; j++) {
                is_prime[i * j] = false;

                //合成数でまだ素数が約数となっていない場合にはiが約数となる
                if(minfactor[i * j] == -1) minfactor[i * j] = i;
            }
        }

        // 1からNまでの素因数分解
        for(int i = 2; i <= n; i++) {
            auto x = factorize(i);
            for(auto y : x) {
                primefactor[i].push_back(y);
            }
        }
    }

    // 素因数分解(Xの素因数を得る)
    // O(LogN)
    // xの<約数,指数>を列挙して返す
    vector<pair<int, int>> factorize(int x) {
        vector<pair<int, int>> res;
        while(x > 1) {
            int p = minfactor[x];
            int exp = 0;

            // Nで割り切れる限り割る
            while(minfactor[x] == p) {
                x /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    //約数列挙(Xの約数を得る)
    //計算量は約数の個数をnとしてO(n)
    //約数の個数は10^9までの数で n <= 1344となる
    vector<int> divisors(int x) {
        vector<int> res({1});

        // xが0以下のときは-1として返す
        if(x <= 0) {
            res[0] *= -1;
            return res;
        }

        //素素因を取得
        auto pf = factorize(x);

        //約数列挙
        for(auto p : pf) {
            int siz = (int)res.size();
            for(int i = 0; i < siz; i++) {
                int v = 1;
                for(int j = 0; j < p.second; j++) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }

    //--------------------------------------------------------------------------
    // debug
    //--------------------------------------------------------------------------

    // nまでの最小の素因数の約数を表示する
    void show_minfactor(int n) {
        rep(i, n) cout << i << ":" << minfactor[i] << " ";
        cout << endl;
    }

    // xの最小の素因数の約数を表示する
    void show_primefactor(int x) {
        cout << x << " の[素因数,指数]" << endl;
        auto pf = primefactor[x];
        for(auto [f, i] : pf) cout << f << " " << i << endl;
        cout << "---------------------------------" << endl;
    }

    // xの約数を列挙する
    void show_divisors(int x) {
        auto d = divisors(x);
        for(auto x : d) cout << x << " ";
        cout << endl;
    }
};
