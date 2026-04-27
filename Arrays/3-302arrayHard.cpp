#include<bits/stdc++.h>
using namespace std;

vector<int> bruteMajorityElement2(vector<int> &nums){
    int n = nums.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        int ele = nums[i];
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(nums[j] == ele){
                if(ans.size() == 0 || ans[0] != ele){
                    cnt++;
                    if(cnt > n/3){
                        ans.push_back(nums[i]);
                    }
                }
            }
        }
        if(ans.size() == 2){
            break;
        }
    }
    return ans; 
}
vector<int> betterMajorityElement2(vector<int> &nums){
    vector<int> ans;
    map<int,int> mpp;
    int min = nums.size()/3 + 1;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]] == min){
            ans.push_back(nums[i]);
        }
        if(ans.size() == 2){
            break;
        }
    }
    return ans;
}
vector<int> optimalMajorityElement2(vector<int> &nums){
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(cnt1 == 0 && nums[i] != ele2){
            cnt1++;
            ele1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != ele1){
            cnt2++;
            ele2 = nums[i];
        }
        else if(nums[i] == ele1){
            cnt1++;
        }
        else if(nums[i] == ele2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == ele1){
            cnt1++;
        }
        else if(nums[i] == ele2){
            cnt2++;
        }
    }

    if(cnt1 > nums.size()/3) ans.push_back(ele1);
    if(cnt2 > nums.size()/3) ans.push_back(ele2);

    return ans;
}
int main()
{
    vector<int> nums = {1,1,1,1,2,2,2,3,3,3};
    vector<int> ans = optimalMajorityElement2(nums);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}
