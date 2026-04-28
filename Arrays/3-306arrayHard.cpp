#include<bits/stdc++.h>
using namespace std;

int bruteSubarrayXORK(vector<int> &nums, int k)
{
    int count = 0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int XR = 0;
            for(int k=i;k<=j;k++){
                XR = XR^nums[k];
            }
            if(XR == k){
                count++;
            }
        }
    }
    return count;
}
int betterSubarrayXORK(vector<int> &nums,int k)
{
    int count = 0;
    for(int i=0;i<nums.size();i++){
        int XR = 0;
        for(int j=i;j<nums.size();j++){
            XR = XR^nums[j];
            if(XR == k){
                count++;
            }
        }
    }
    return count;
}
int optimalSubarrayXORK(vector<int> &nums,int k){
    int count = 0;
    map<int,int> mpp;
    int XOR = 0;
    mpp[XOR]++;
    for(int i=0;i<nums.size();i++){
        XOR = XOR^nums[i];
        int x = XOR^k;
        if(mpp.find(x) != mpp.end()){
            count += mpp[x];
        }
        // OR-> count += mpp[x];
        mpp[XOR]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {0,0,0,0};
    int ans = optimalSubarrayXORK(nums,0);
    cout<<"Ans " << ans;
}