long long power(long long a, long long b) {
	if (b==0) return 1;
	if (b==1) return a;
	long long tmp=power(a, b/2);
	tmp=tmp*tmp;//%mod;
	if (b%2) return tmp*a;//%mod;
	return tmp;
}