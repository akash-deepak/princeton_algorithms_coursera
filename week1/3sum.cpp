# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int binarySearch(int val, vector<int> varr, int low, int high){
    int mid;
    while(low<=high){
        mid = (high + low)/2;
        if(varr[mid] < val) low = mid + 1;
        else if (varr[mid] > val) high = mid - 1;
        else return 1;
    }
    return -1;
}

void _3sum(vector<int> varr){
    sort(varr.begin(), varr.end());
    int length = varr.size();
    int check;
    for(int i = 0; i < length - 2; i++){
        for(int j = i+1; j < length - 1; j++){
            check = binarySearch(-(varr[i] + varr[j]), varr, j+1, length - 1);
            if(check == 1) cout<<varr[i]<<" "<<varr[j]<<" "<<-(varr[i] + varr[j])<<endl;
        }
    }
}

int main(){
    int arr[] = {30, -40, -20, -10, 40, 0, 10, 5};
    vector<int> varr(arr, arr + sizeof(arr)/sizeof(arr[0]));
    _3sum(varr);
    return 0;
}
