class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // M1 -> find all permulation store in vector then find next permutation all possible permutations, it is taking N!xN. 
        // M2 -> in c++ we have inbuild function   next_permutation(nums.begin(),nums.end());
        // M3-> prefix same then find a break point and elment to place at position of break point sort the rest
        int n = nums.size();
        int i =0; 
        for(i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        // element to be placed -> just greater 
        for(int j =n-1;j>i && i != -1;j--){
            if(nums[j]>nums[i]){
                swap(nums[j],nums[i]);
                break;
            }
        }
        // sort the remaining 
        reverse(nums.begin()+i+1,nums.end());
        // edge case -> [3,2,1]
        // sc = O(1);
        // tc = O(n)
    }
};