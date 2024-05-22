int gcd(int a, int b) {
    if (a%b==0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a/gcd(a, b)*b;
}
