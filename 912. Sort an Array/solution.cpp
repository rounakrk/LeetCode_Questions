class Solution {
public:

    void merge(vector<int> &arr, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;

        vector<int> a(n1);
        vector<int> b(n2);

        for(int i = 0; i<n1; i++) a[i] = arr[left+i];
        for(int i = 0; i<n2; i++) b[i] = arr[mid+1+i];

        int i=0;
        int j=0;
        int k = left;

        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                arr[k] = a[i];
                i++;
            }else{
                arr[k] = b[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k] = a[i];
            k++;
            i++;
        }

        while(j<n2){
            arr[k] = b[j];
            j++;
            k++;
        }

    }

    void mergeSort(vector<int> &arr, int left, int right){
        if(left>=right) return;

        int mid = left + (right-left)/2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};