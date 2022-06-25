ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp;//%mod;
	if (b%2) return tmp*a;//%mod;
	return tmp;
}