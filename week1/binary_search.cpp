# include <iostream>
using namespace std;
int binarySearch(int a[], int n, int val){
    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(a[mid] < val) low = mid + 1;
        else if(a[mid] > val) high = mid - 1;
        else return mid;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 5, 8, 10, 15, 25, 26, 89, 100};
    int sizeofarr = sizeof(arr)/sizeof(arr[0]);
    int number;
    cout<<"Enter an integer to search "<<endl;
    cin>>number;
    int position = binarySearch(arr, sizeofarr, number);
    if(position != 1) cout<<"Number found at position "<<position<<endl;
    else cout<<"Number not found"<<endl;
    return 0;
}
