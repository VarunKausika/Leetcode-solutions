void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (m == 0){
        for(int i = 0; i < n; i++){
            nums1[i] = nums2[i];
        }
    }
    else if (n == 0){
        ;
    }
    else{
        int i, j = 0;
        int k;
        for(i = 0; i<nums1Size; i++){
            if (j > n-1){
                break;
            }
            if (i > m-1+j){
                nums1[i] = nums2[j];
                j++;
                continue;
            }
            if (nums1[i]>=nums2[j]){
                for (k = m+n-1; k>i; k--){
                    nums1[k] = nums1[k-1];
                }
                nums1[i] = nums2[j];
                j++;
            }
        }
    }
}