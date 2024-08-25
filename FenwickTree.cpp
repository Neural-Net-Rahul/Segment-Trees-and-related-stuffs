#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Fenwick llree / Binary Indexed llree
// Point Update and Range query in log(N)

class BIT{
  private:
    ll size;
    vector<ll> bit;
    vector<ll> arr;

  public:
    BIT(ll size) : size(size), bit(size + 1), arr(size) {}

    void set(ll ind, ll val) { add(ind, val - arr[ind]); }

    void add(ll ind, ll val) {
        arr[ind] += val;
        ind++;
        for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
    }

    ll pref_sum(int ind) {
        ind++;
        ll total = 0;
        for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
        return total;
    }
};

int main(){
    ll arr_len;
    cin>>arr_len;
    BIT bit(arr_len);
    for (ll i = 0; i < arr_len; i++) {
        ll n;
        std::cin >> n;
        bit.set(i, n);
    }
    bit.set(3,5);
    bit.add(4,6);
    cout<<bit.pref_sum(5)<<endl;
    cout<<bit.pref_sum(6)-bit.pref_sum(2)<<endl;
}
