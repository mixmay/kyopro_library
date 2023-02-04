// lower_bound:配列に含まれるX以上の"インデックス"を返す、なければ配列外を返す(size)
template <typename T> T LINDEX(T x, vector<T> &A) {
    auto itr = lower_bound(all(A), x);
    T idx = itr - A.begin();
    return idx;
}
// lower_bound:配列に含まれるX以上の"値"を返す。なければ-1を返す
template <typename T> T LVALUE(T x, vector<T> &A) {
    auto itr = lower_bound(all(A), x);
    T value;
    if(itr == A.end())
        value = -1;
    else
        value = *itr;
    return value;
}
// upper_bound:配列に含まれるXより大きい"インデックス"を返す、なければ配列外を返す(size)
template <typename T> T UINDEX(T x, vector<T> &A) {
    auto itr = upper_bound(all(A), x);
    T idx = itr - A.begin();
    return idx;
}
// upper_bound:配列に含まれるXより大きい"値"を返す、なければ-1を返す
template <typename T> T UVALUE(T x, vector<T> &A) {
    auto itr = upper_bound(all(A), x);
    T value;
    if(itr == A.end())
        value = -1;
    else
        value = *itr;
    return value;
}
