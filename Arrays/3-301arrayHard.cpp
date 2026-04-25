#include<bits/stdc++.h>
using namespace std;
int optimalPascalsTriangleElement(int n, int r){
    // Type01 : Given row and column return the element at the position(N,r)
    int N = n-1;
    int R = r-1;
    int res = 1;
    for(int i=0;i<R;i++){
        res = res * (N-i);
        res = res / (i+1);
    }
    return res;
}
vector<int> brutePascalsTriangleRow(int r){
    // Type02 : Given row number return the entire row of Pascal's triangle(Brute)
    vector<int> ans;
    for(int i=0;i<r;i++){
        ans.push_back(optimalPascalsTriangleElement(r,i+1));
    }
    return ans;
}
vector<int> optimalPascalstriangleRow(int r){
    // Type02 : Given row number return the entire row of Pascal's triangle(Optimal)
    vector<int> answer;
    int ans = 1;
    answer.push_back(ans);
    for(int i=1;i<r;i++){
        ans = ans*(r-i);
        ans = ans/i;
        answer.push_back(ans);
    }
    return answer;
}
vector<vector<int>> optimalPascalstriangle(int n){
    // Type 03 : Given number of rows generate the first n rows of pascal's triangle
    vector<vector<int>> ans;
    for(int i=1;i<=n;i++){
        vector<int> currRowAns = optimalPascalstriangleRow(i);
        ans.push_back(currRowAns);
    }
    return ans;
}
int main()
{
    // int ans = optimalPascalsTriangleElement(1,1);
    // vector<int> ans = brutePascalsTriangleRow(1);
    vector<vector<int>> ans = optimalPascalstriangle(5);
    int row = ans.size();
    for(int i=0;i<row;i++){
        int col = ans[i].size();
        for(int j=0;j<col;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}