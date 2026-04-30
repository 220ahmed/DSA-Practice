#include<bits/stdc++.h>
using namespace std;

vector<int> bruteFindMissingRepeatingNumber(vector<int> &nums, int n){
    int size = nums.size();
    int rptNo = -1;
    int misNo = -1;
    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<size;j++){
            if(nums[j] == i) cnt++;
        }
        if(cnt == 2) rptNo = i;
        else if(cnt == 0) misNo = i;
        if(misNo != -1 && rptNo != -1) break;
    }
    return {rptNo , misNo}; 
}
vector<int> betterFindMissingRepeatingNumber(vector<int> &nums, int n){
    vector<int> hash (n+1,0);
    int rptNo = -1;
    int misNo = -1;
    for(int i=0;i<nums.size();i++){
        hash[nums[i]]++;
    }
    for(int i=0;i<hash.size();i++){
        if(hash[i] == 2) rptNo = i; 
        else if(hash[i] == 0) misNo = i; 
    }

    return {rptNo,misNo};
}
vector<int> optimalFindMissingRepeatingNumber(vector<int> &nums,int n){
    int x , y;
    int sumNat = n*(n+1)/2;
    int sumNatSq = n*(n+1)*(2*n+1) / 6;
    int sumArr = 0;
    int sumArrSq = 0;
    for(int i=0;i<nums.size();i++){
        sumArr += nums[i];
        sumArrSq += nums[i] * nums[i]; 
    }
    // x-y
    int val1 = sumNat - sumArr;
    // x2 - y2
    int val2 = sumNatSq - sumArrSq;
    // x+y
    val2 = val2/val1;
    x = (val1+val2) / 2;
    y = x-val1;
    return {x,y};

}
int main()
{
    vector<int> nums = {4,6,5,2,1,4};
    int n = 6;
    vector<int> ans = betterFindMissingRepeatingNumber(nums,n);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}