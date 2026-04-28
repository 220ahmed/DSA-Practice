#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteMergeOverlappingInterval(vector<vector<int>> &nums){
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        int start = nums[i][0];
        int end = nums[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(nums[j][0] <= end){
                end = max(end,nums[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
vector<vector<int>> optimalMergeOverlappingInterval(vector<vector<int>> &nums){
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(ans.empty() || ans.back()[1] < nums[i][0]){
            ans.push_back({nums[i][0],nums[i][1]});
        }
        else{
            ans.back()[1] = max(ans.back()[1],nums[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> nums = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    vector<vector<int>> ans = optimalMergeOverlappingInterval(nums);
    int n = ans.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}