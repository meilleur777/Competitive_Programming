#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums) {
    int ret=0;
    int n=nums.size();
    for (int i=0; i<n-2; i++) {
        for (int j=i+1; j<n-1; j++) {
            for (int k=j+1; k<n; k++){
                int num=nums[i]+nums[j]+nums[k];
                
                bool flag=true;
                for (int l=2; l*l<=num; l++) {
                    if (num%l==0) {
                        flag=false;
                        break;
                    }
                }
                
                ret+=flag;
            }
        }
    }
    return ret;
}