#include<bits/stdc++.h>
using namespace std;

int bruteLongestSubarraySumZero(vector<int> &nums)
{
    int maxi = 0;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += nums[k];
            }
            if(sum == 0){
                maxi = max(maxi,j-i+1);
            }
        }
    }
    return maxi;
}
int betterLongestSubarraySumZero(vector<int> &nums)
{
    int maxi = 0;
    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];
            if(sum == 0){
                maxi = max(maxi,j-i+1);
            }
        }
    }
    return maxi;
}
int optimalLongestSubarraySumZero(vector<int> &nums){
    map<int,int> mpp;
    int maxi = 0;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        sum += nums[i];   
        if(sum == 0){
            maxi = i + 1;
        }
        if(mpp.find(sum) != mpp.end()){
            maxi = max(maxi,mpp[sum]-i+1);
        }
        mpp[sum] = i;
    }
    return maxi;
}

int main()
{
    vector<int> nums = {1,-1,2,-2,3};
    int ans = optimalLongestSubarraySumZero(nums);
    cout<<"Ans " << ans;
}