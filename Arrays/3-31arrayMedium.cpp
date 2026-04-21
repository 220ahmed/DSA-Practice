#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bruteRotMat90(vector<vector<int>> &nums){
    int row = nums.size();
    int col = nums[0].size();
    vector<vector<int>> ans(row,vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ans[j][(row-i)-1] = nums[i][j];
        }
    }
    return ans;
}
void optimalRotMat90(vector<vector<int>> &nums){
    // transpose the matrix (row->col | col->row) we can do this by swapping elements on the right of the diagnal
    int n = nums.size();
    int m = nums[0].size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<m;j++){
            swap(nums[i][j],nums[j][i]);
        }
    }

    // reverse every row and the resultant matrix will be rot by 90degree
    for(int i=0;i<m;i++){
        reverse(nums[i].begin(),nums[i].end());
    }
}
int main()
{
    vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int row = nums.size();
    int col = nums[0].size();
    // vector<vector<int>> ans = bruteRotMat90(nums);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    optimalRotMat90(nums);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}