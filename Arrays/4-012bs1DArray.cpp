#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &nums,int x){
    int ans = nums.size();
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid  + 1; 
        }
    }
    return ans;
}
int ceilLowerBound(vector<int> &nums,int x){
    // this is same as lower bound but it returns the value instead of index
    int ans = -1;
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] >= x){
            ans = nums[mid];
            high = mid - 1;
        }
        else{
            low = mid  + 1; 
        }
    }
    return ans;
}
int upperBound(vector<int> &nums,int x){
    int ans = nums.size();
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
}
int insertAtPosition(vector<int> &nums,int x){
    return lowerBound(nums,x);
}
int floor(vector<int> &nums,int x){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] <= x){
            ans = nums[mid];
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
pair<int,int> floorCeil(vector<int> &nums,int x){
    pair<int,int> ans;
    ans.first = floor(nums,x);
    ans.second = ceilLowerBound(nums,x);
    return ans;
}
int main()
{
    vector<int> nums = {10,20,25,30,40,50};
    int x = 25;
    pair<int,int> ans = floorCeil(nums,x);
    cout<<ans.first <<" " <<ans.second;
    return 0;
}