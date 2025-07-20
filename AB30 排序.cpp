class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    void Merge(vector<int>& arr, int l, int r){
        int mid = (l+r)/2;
        int lenL = mid - l + 1;
        int lenR = r - mid;
        int *L = new int[lenL];
        int *R = new int[lenR];
        for (int i = 0; i < lenL; i++){
            L[i] = arr[l+i];
        }
        for (int i = 0; i < lenR; i++){
            R[i] = arr[mid+1+i];
        }
        int i = 0;
        int j = 0;
        for (int idx = l; idx <= r; idx++){
            if(j>=lenR || (i<lenL && L[i] < R[j]))
            {
                arr[idx] = L[i];
                i++;
            }
            else{
                arr[idx] = R[j];
                j++;
            }
        }
        delete []L;
        delete []R;
    }

    void mergeSort(vector<int>& arr, int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            Merge(arr, l, r);
        }
    }

    vector<int> MySort(vector<int>& arr) {
        // write code here
        int n = arr.size();
        mergeSort(arr, 0, n-1);
        return arr;
    }
};
