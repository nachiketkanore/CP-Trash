#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
string vals[N];
string A, B, pattern;
string add;
int dp[15][2][2][15];


string get_smallest(string s) {
	if (s[0] == '?') s[0] = '1';
	for (char &ch : s) 
		if (ch == '?')
			ch = '0';
	return s;
}


int go(int pos, bool bigA, bool smallB, int id){
    if (id == sz(pattern))
    	return 1;

    int &ans = dp[pos][bigA][smallB][id];
    if(~ans)
        return ans;
    ans = 0;
    for(int i = 0; i < 10; i++){
        if(!bigA && i < A[pos] - '0')   continue;
        if(!smallB && i > B[pos] - '0') continue;

        if (pattern[id] == '?' || (pattern[id] - '0' == i))
        	ans |= go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), id + 1);
    }
    return ans;
}


void trace(int pos, bool bigA, bool smallB, int id){
    if (id == sz(pattern))
    	return ;

    int ans = go(pos, bigA, smallB, id);

    for(int i = 0; i < 10; i++){
        if(!bigA && i < A[pos] - '0')   continue;
        if(!smallB && i > B[pos] - '0') continue;

        if (pattern[id] == '?' || (pattern[id] - '0' == i)) {
        	int get = go(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), id + 1);
        	if (ans == get) {
        		add.push_back((char)(i + '0'));
        		return trace(pos + 1, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), id + 1);
        	}
        }
    }
}

void fk() {
	cout << "NO\n";
	exit(0);
}


string find_best(string L, string R) {

    memset(dp, -1, sizeof(dp));
    if (sz(L) != sz(R)) fk();
    if (sz(L) != sz(pattern)) fk();
    A = L, B = R;
    reverse(A.begin(), A.end());
    while(sz(A) < sz(B))
        A.push_back('0');
    reverse(A.begin(), A.end());
    int ans = 0;

    for(int i = 0; i < 10; i++) {
        if(i < A[0] - '0')  continue;
        if(i > B[0] - '0')  continue;

        if (pattern[0] == '?' || (pattern[0] - '0' == i))
        	ans |= go(1, i > A[0] - '0', i < B[0] - '0', 1);
    }

    if (!ans) {
    	cout << "NO\n";
    	exit(0);
    }

    add.clear();

    for(int i = 0; i < 10; i++) {
        if(i < A[0] - '0')  continue;
        if(i > B[0] - '0')  continue;

        if (pattern[0] == '?' || (pattern[0] - '0' == i)) {
			int get = go(1, i > A[0] - '0', i < B[0] - '0', 1);
			if (get == ans) {
				add.push_back((char)(i + '0'));
				trace(1, i > A[0] - '0', i < B[0] - '0', 1);
				break;
			}
        }
    }

    if (sz(add) != sz(pattern)) fk();
    return add;
}


string get_best(string one, string two) {
	assert(sz(one) == sz(two));
	int len = sz(one);

	pattern = two;
	string big;
	FOR(i,1,len) big.push_back('9');
	int L = stoll(one) + 1;

	string ret = find_best(to_string(L), big);
	return ret;
}

bool chk(string one_, string two_) {
	if (sz(one_) > sz(two_)) return false;
	if (sz(one_) < sz(two_)) return true;
	return one_ < two_;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	FOR(i,1,n) {
		cin >> vals[i];
	}
	vals[1] = get_smallest(vals[1]);

	FOR(i,2,n) {
		if (sz(vals[i - 1]) < sz(vals[i]))
			vals[i] = get_smallest(vals[i]);
		else if (sz(vals[i - 1]) > sz(vals[i])) {
			cout << "NO\n";
			return 0;
		} else {
			vals[i] = get_best(vals[i - 1], vals[i]);
		}
	}

	bool ok = true;
	FOR(i,2,n) ok &= chk(vals[i - 1], vals[i]);
	if (!ok) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		FOR(i,1,n) {
			cout << vals[i] << '\n';
		}
	}
}
