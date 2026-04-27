#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> bruteThreeSum(vector<int> &nums,int tar){
    int n = nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i] + nums[j] + nums[k] == tar){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans (st.begin(),st.end());
    return ans;
}
vector<vector<int>> betterThreeSum(vector<int> &nums, int tar){
    set<vector<int>> st;
    for(int i=0;i<nums.size();i++){
        set<int> hashSet;
        for(int j=i+1;j<nums.size();j++){
            int third = -(nums[i] + nums[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp = {nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    } 
    return vector<vector<int>> (st.begin(),st.end());
}
vector<vector<int>> optimalThreeSum(vector<int> &nums,int tar)
{
    int n = nums.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j < k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum > 0){
                k--;
            }
            else if(sum < 0){
                j++;
            }
            else{
                vector<int> temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]) j++;
                while(j<k && nums[k] == nums[k+1]) k++;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {-2,0,1,1,2};
    vector<vector<int>> ans  = optimalThreeSum(nums,0);
    int n = ans.size();
    int m = ans[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
    }
    return 0;
}