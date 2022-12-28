//めぐる式 二分探索
bool isOK(ll mid) {
    //条件を満たすかどうか
    if(true) {
        return true;
    } else {
        return false;
    }
}

//条件を満たす最少の数を返す
//範囲内に条件を満たす場所が存在しない場合-1を返す
// ng、okはどちらも範囲外に設定
//条件を満たす中で最大を求めるときはMAXをNGにMINをOKにする
ll binary_search(ll ng, ll ok) {
    int over1 = ng, over2 = ok;
    while(abs(ok - ng) > 1) {
        ll left = min(ok, ng);
        ll right = max(ok, ng);
        ll mid = left + (right - left) / 2;
        // midが条件を見満たしている間right = mid
        if(isOK(mid)) {
            ok = mid;
        }
        //そうでなければleft = mid
        else {
            ng = mid;
        }
    }
    //条件を満たさない<=left < right<=条件を満たす
    // leftは条件を満たさない最大の数、rightは条件を満たす最少の数
    ll ans = ok;
    //範囲外にある場合の判定
    if(ans == over1 || ans == over2) {
        ans = -1;
    }
    return ans;
}
