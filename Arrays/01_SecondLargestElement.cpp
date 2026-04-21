#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int largestElement(vector<int> &nums){
    int largest = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > largest){
            largest = nums[i];
        }
    }
    return largest;
}
int secondLargestBrute(vector<int> &nums){
        sort(nums.begin(),nums.end());
        int largest = nums[nums.size() - 1];
        int secondLargest = INT_MIN;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] != largest && nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }
        return secondLargest;
}
int secondLargestBetter(vector<int> &nums){
    int largest = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > largest){
                largest = nums[i];
            }
        }
    int secondLargest = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > largest && nums[i] != largest){
            secondLargest = nums[i];
        }
    }
    return secondLargest;
}
int secondLargestOptimal(vector<int> &nums){
    int largest = nums[0];
    int secondLargest = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }

        if(nums[i] < largest && nums[i] > secondLargest){
            secondLargest = nums[i];
        }
    }
    return secondLargest;
}
bool isArraySorted(vector<int> &nums){
    for(int i=0;i<nums.size()-1;){
        // check if every next elem is bigger than current
        if(nums[i] <= nums[i+1]){
            i++;
        }
        else{
            return false;
        }
    }
    return true;
}
vector<int> removeDuplicatesBrute(vector<int> &nums){
    set<int> st;
    //insert all elem in set (unique and in non-dec order)
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }
    int index = 0;
    // iterate over set and update ith elem in nums
    for(auto it : st){
        nums[index] = it; 
        index++;
    }
    return nums;
}
int removeDuplicatesOptimal(vector<int> &nums){
    // it is a sorted array first elem will be unique
    int i = 0;
    //iterate over array and update elem at [i+1] with elem at [j] when unique elem is found --> increment i++
    for(int j=1;j<nums.size();j++){
        if(nums[j] != nums[i]){
            nums[i+1] = nums[j];
            i++;
        }
    }
    return (i+1);
}
int main()
{
    vector<int> nums = {3,3,4,4,5,5,6};
    int ans = removeDuplicatesOptimal(nums);
    cout<<ans;
    return 0;
}