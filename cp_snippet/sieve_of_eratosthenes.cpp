vector<bool> ispri(/*bound*/, true);

void sieve() {
	ispri[0]=ispri[1]=false;
	for (int i=2; i*i<=/*bound*/; i++) {
		for (int j=i*2; j<=/*bound*/; j+=i) {
			ispri[j]=false;
		}
	}
}
