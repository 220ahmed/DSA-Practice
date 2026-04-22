#include<bits/stdc++.h>
using namespace std;
vector<int> spiralPrintMatrix(vector<vector<int>> &nums){
    int n = nums.size();
    int m = nums[0].size();
    vector<int> ans;
    int left = 0, top = 0;
    int right = m-1, bottom = n-1;
    while(left <= right && top <= bottom){
        // right
        for(int i=left;i<=right;i++){
            ans.push_back(nums[top][i]);
        }
        top++;
        // bottom
        for(int i=top;i<=bottom;i++){
            ans.push_back(nums[i][right]);
        }
        right--;
        // left
        if(top <= bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(nums[bottom][i]);
            }
            bottom--;
        }
        // top
        if(left <= right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(nums[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> nums = {{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
    vector<int> ans = spiralPrintMatrix(nums);
    int n = ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i] <<" ";
    }
    return 0;
}