using namespace std;

long long solution(int price, int money, int count) {
    long long cost=0;
    for (long long i=1; i<=count; i++) {
        cost+=price*(i);
    }
    long long lmoney=money;
    lmoney-=cost;
    if (lmoney>=0) return 0;
    return -1*lmoney;
}