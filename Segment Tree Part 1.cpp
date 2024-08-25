#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Segment Tree
// Point Update and Range query in log(N)

class SegmentTree{
public:
    vector<ll>baseArray;
    vector<ll>segtree;
    SegmentTree(ll n,vector<ll>&arr){
        baseArray.resize(n);
        segtree.resize(4*n);
        for(ll i =0;i<n;i++){
            baseArray[i] = arr[i];
        }
    }
    void build(ll beg, ll end, ll pos) {
        ll mid = (beg+end)/2;
        if(beg == end) {
            segtree[pos] = baseArray[beg];
            return;
        }
        build(beg, mid, 2*pos+1);
        build(mid+1, end, 2*pos+2);
        segtree[pos] = min(segtree[2*pos+1] , segtree[2*pos+2]);
    }
     
    void update(ll beg, ll end,ll pos, ll idx, ll val) {
        ll mid = (beg+end)/2;
        if(beg == end) {
            segtree[pos] = val;
            return;
        }
        if(idx <= mid) {
            update(beg, mid, 2*pos+1, idx, val);
        } else {
            update(mid+1, end, 2*pos+2, idx, val);
        }
        segtree[pos] = min(segtree[2*pos+1] , segtree[2*pos+2]);
    }
     
    ll query(ll beg, ll end, ll pos, ll ql, ll qr) {
        if(ql<=beg and qr>=end) {
            return segtree[pos];
        } else if(ql>end or qr<beg) {
            return INT_MAX;
        }
        ll mid = (beg+end)/2;
        return min(query(beg, mid, 2*pos+1, ql, qr) , query(mid+1, end, 2*pos+2, ql, qr));
    }
};

int main(){
    vector<ll>v = {3,5,7,6,4,2,7,9};
    SegmentTree s1(8,v);
    s1.build(0,7,0);
    cout<<s1.query(0,7,0,2,5)<<endl;
    s1.update(0,7,0,0,5);
    cout<<s1.query(0,7,0,1,3)<<endl;
    s1.update(0,7,0,5,150);
    cout<<s1.query(0,7,0,2,7)<<endl;
    s1.update(0,7,0,7,1);
    cout<<s1.query(0,7,0,6,7)<<endl;
}
