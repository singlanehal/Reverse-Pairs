class Solution {
public:
    int count = 0;
    void merge(int low,int mid,int high,vector<int>& nums)
    {
        int n1 = mid - low +1;
        int n2 = high - mid;
        vector<int> l(n1),r(n2);
        for(int i=0;i<n1;i++)
        {
            l[i] = nums[low+i];
        }
        for(int i=0;i<n2;i++)
        {
            r[i] = nums[mid+1+i];
        }
        //count reverse pairs
        int j = mid +1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high && (long long)nums[i]>2LL*nums[j])
            {
                j++;
            }
            count += (j-(mid+1));
        }
        
        //merge 2 sorted list
        int i=0;
        j=0;
        int k = low;
        while(i<n1 && j<n2)
        {
            if(l[i]<=r[j])
            {
                nums[k++] = l[i++];
            }
            else
            {
                nums[k++] = r[j++];
            }
        }
        while(i<n1) nums[k++] = l[i++];
        while(j<n2) nums[k++] = r[j++];

    }
    void merge_sort(int low,int high,vector<int>&nums)
    {
        if(low>=high)
        {
            return;
        }
        int mid = (low+high)/2;
        merge_sort(low,mid,nums);
        merge_sort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        merge_sort(0,n-1,nums);
        return count; 
      //brute force 
        /*int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                if(nums[i]>2*nums[j])
                {
                    count++;
                }
            }
        }
        return count;*/
    }
};
