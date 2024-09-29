class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // M1 -> find the sum of all subarr -> O(N^2);

        int maxi = 1e-7;
        int n = nums.size();
        for(int i =0;i<n;i++){
            int sum = 0;
            for(int j =i;j<n;j++){
                sum+=nums[j];
                if(maxi<sum) maxi = sum;
            }
        }
        return maxi;

        //M2 -> l=kadane algo -> A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum. O(N)
        int n = nums.size();
        int maxi = nums[0];
        int sum = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];
            if(maxi <sum) maxi = sum;
            if(sum <0) sum =0;
        }
        return maxi;

    }
};

// if u want to print the array 
     
        int n = nums.size();
        int maxi = nums[0];
        int sum = 0;
        int start = 0;
        int ansstart =0;
        int ansend=0;
        for(int i =0;i<n;i++){
            sum += nums[i];
            if(maxi <sum) {
                maxi = sum;
                ansstart = start;
                ansend = i;
            }
            if(sum <0) {
                sum =0;
                start = i+1;
            }
        }
