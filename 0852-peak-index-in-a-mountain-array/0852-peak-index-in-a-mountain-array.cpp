class Solution {
public:


    int binary(vector<int>& arr,int l,int r){
        
        int mid=l + (r - l) / 2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return mid;
        else if(arr[mid]>arr[mid-1]){
            l=mid;
            return binary(arr,l,r);
        }
        else{
            r=mid;
            return   binary(arr,l,r);
        }
    }

    int peakIndexInMountainArray(vector<int>& arr) {

        int l=0,r=arr.size();

        return binary(arr,l,r);
        
    }
};