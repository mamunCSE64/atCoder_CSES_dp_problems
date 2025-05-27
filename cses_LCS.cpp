#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define gcd __gcd
#define int_string to_string
#define string_int stoi
#define mn(v) *min_element(v.begin(), v.end())
#define mx(v) *max_element(v.begin(), v.end())
#define index_character s.find('character')
#define countxchar count(s.begin(), s.end(), 'x')
#define index_ofX_vector find(v.begin(), v.end(), x) - v.begin()
#define point cout << fixed << setprecision(10)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define n1 cout << "-1" << endl
#define ok cout << "ok" nl
#define sorted is_sorted(v.begin(), v.end())
#define nl << endl
#define sp << " "
#define mp make_pair
#define fi first
#define se second
#define inf LLONG_MAX
#define mod %1000000007
// ordered_set
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// bitsize-> ll size=log2(n)+1 (last set bit=size-1;/ /Last bit->__lg(value); )
// first bit-> name._Find_First()
// next bit after x-> name._Find_next()
// freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// BesidesDuplicateCharacterEraseInString s.erase(unique(s.begin(), s.end()), s.end());
// Upper/lower-> transform(s.begin(), s.end(), s.begin(), ::toupper/tolower);
 
ll i, j, k, n, m, e=1e9;
const ll N = 2e6+5;
double pi=acos(-1);
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    if(a.fi==b.fi) return (a.se>b.se); return (a.fi>b.fi);}
 
//
// Don't get stuck on a single approach for long, think of multiple ways
// You will destroy your dream if you stay in your comfort zone
// **********************|| Main Code ||********************************
//
 
//  g++ test.cpp -o a && ./a
//  g++ -o a test.cpp && ./a
//  g++ -o a test.cpp && a.e
 
 
int main()
{ 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    // point;
    int test = 1; 
    // cin >> test;    
    again: 
    while (test--)
    {   
        ll n,m;
        cin>>n>>m;
        vector<ll> s(n+1),t(m+1);
        for(i=1;i<=n;i++){
            cin>>s[i];
        }
        for(i=1;i<=m;i++){
            cin>>t[i];
        }
        vector<vector<ll>> dp(n+1,vector<ll> (m+1));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(s[i]==t[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        vector<ll> ans;
        i=n,j=m;
        while(i>0 and j>0){
            if(s[i]==t[j]){
                ans.pb(s[i]);
                i--,j--;
            }else if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }else i--;
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() nl;
        for(auto x: ans){
            cout <<  x sp;
        }
        cout nl;
    }
}
