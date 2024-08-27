#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const int maxn = 10086;

string make_it_string(int k) 
{
	int reverse[maxn] = {0}, len=0;
	string to;
	while (k) reverse[len] = k % 10, k /= 10, len++;
	for(int i = len - 1; i >= 0; i--) to += (reverse[i] + '0');
	return to;
}

int find_frac(int &n, int &m)
{
	int k = m / n + 1;
	int factor = __gcd(n * k - m, m * k);
	n = (n * k - m) / factor, m = m * k / factor;
	return k;
}

int main()
{
	int n, m;
	while (cin >> n >> m) 
    {
		int f = 0, fl = 1;
		string ans;

		// do not forget this simplification ,in case n==m
		int _ = __gcd(n, m);
		n /= _, m /= _;
	
		while (n != 1) 
        {
			int k = find_frac(n, m);
			if (k < 1) 
            {
                std::cout << "No found!" << '\n';
                fl = 0;
                break;
            }
	
			ans += (f ? "+" : "");
			ans += "1";
			ans += "/" + make_it_string(k);
	
			if (!f) f = 1;
		}

		if (n == 1) 
        { 
			ans += (f ? "+" : "");
			ans += "1";
			ans += "/" + make_it_string(m / n);
		}
	
		if (fl) std::cout << ans << '\n';
	}

	return 0;
}
