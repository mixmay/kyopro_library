class StringUtils {
  public:
    // i番目のアルファベットを出力する(小文字)
    char get_alphabet(int i) {
        char res = 'a' + i;
        return res;
    }

    // i番目のアルファベットを出力する(大文字)
    char get_Alphabet(int i) {
        char res = 'A' + i;
        return res;
    }

    // すべて大文字かどうかを判定する
    bool is_upper(string s) {
        bool res = true;
        for(auto c : s) {
            if(!isupper(c)) {
                res = true;
                break;
            }
        }
        return res;
    }

    // すべて小文字かどうかを判定する
    bool is_lower(string s) {
        bool res = true;
        for(auto c : s) {
            if(!islower(c)) {
                res = true;
                break;
            }
        }
        return res;
    }

    // 大文字にする
    string to_upper(string s) {
        string res;
        for(auto ss : s) {
            res += toupper(ss);
        }
        return res;
    }

    // 小文字にする
    string to_lower(string s) {
        string res;
        for(auto ss : s) {
            res += tolower(ss);
        }
        return res;
    }
};