class StringUtils {
public:
    // i番目のアルファベットを返す(小文字)
    char get_alphabet(int i) {
        char res = 'a' + i;
        return res;
    }

    // i番目のアルファベットを返す(大文字)
    char get_Alphabet(int i) {
        char res = 'A' + i;
        return res;
    }


    // すべて大文字かどうかを判定する
    bool is_upper(string s) {
        bool res = true;
        for (auto c : s) {
            if (!isupper(c)) {
                res = true;
                break;
            }
        }
        return res;
    }

    // すべて小文字かどうかを判定する
    bool is_lower(string s) {
        bool res = true;
        for (auto c : s) {
            if (!islower(c)) {
                res = true;
                break;
            }
        }
        return res;
    }

    // 大文字にする
    string to_upper(string s) {
        string res;
        for (auto ss : s) {
            res += toupper(ss);
        }
        return res;
    }

    // 小文字にする
    string to_lower(string s) {
        string res;
        for (auto ss : s) {
            res += tolower(ss);
        }
        return res;
    }

    // i番目からj文字取り出す
    string sub_str(string s, int i, int j) {
        return s.substr(i, j);
    }

    // 文字列tが文字列sの連続部分文字列かどうか
    // O(NM) N=s.size() , M= t.size()
    bool is_substr(string s, string t) {
        int n = s.size();
        int m = t.size();
        bool res = false;
        // スタートの位置がi
        for (int i = 0; i+m-1 < n; i++) {
            bool x = true;
            // スタートの位置からj文字目
            for (int j = 0; j < m; j++) {
                if (s[i + j] != t[j]) {
                    x = false;
                    break;
                }
            }
            if (x) res = true;
        }
        return res;
    }

    // 文字列s,tの最長共通部分列(LCS)を返す
    // O(NM) N=s.size() , M= t.size()
    string lcs(string s, string t) {

        int n = s.size(), m = t.size();
        // s[i],t[j]までの最長共通部分列の長さ
        vector<vector<int>> DP(n+1, vector<int>(m+1,0));
        s.insert(s.begin(), ' ');
        t.insert(t.begin(), ' ');
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                DP[i][j] = max(DP[i - 1][j],DP[i][j - 1]);
                if (s[i] == t[j]) DP[i][j] = max(DP[i][j], DP[i - 1][j - 1] + 1);
            }
        }

        // 復元
        int i = n, j = m;
        string res;
        while (i > 0 && j > 0) {
            if (DP[i][j] == DP[i - 1][j]) {
                --i;
                continue;
            }
            if (DP[i][j] == DP[i][j - 1]) {
                --j;
                continue;
            }
            res += s[i];
            --i, --j;
        }
        reverse(all(res));
        return res;
    }
};
