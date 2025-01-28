// Sum of all Subarrays
// #include <iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum=sum+((n-i)*a[i]*(i+1));
//     }
//     cout<<"Sum is: "<<sum;

// }
//find Pivot element 724
//
//  Sum of range of all subarrays
//34
//162
//33
//2020b codeforces

// 2104. Sum of Subarray Ranges
// #include <iostream>
// #include <vector>
// #include <stack>
// #include <map>
// #include <functional>

//     using namespace std;

// class Solution
// {
// public:
//     long long subArrayRanges(vector<int> &arr)
//     {
//         // This element will be minimum in how many subarrays and will be maximum in how many subarrays
//         int n = int(arr.size());

//         vector<int> nsev(n, 0);
//         function<void()> nse = [&]()
//         {
//             stack<int> st;
//             for (int i = n - 1; i >= 0; i--)
//             {
//                 while (!st.empty() && arr[st.top()] >= arr[i])
//                 {
//                     st.pop();
//                 }
//                 if (st.empty())
//                 {
//                     nsev[i] = n;
//                 }
//                 else
//                 {
//                     nsev[i] = st.top();
//                 }
//                 st.push(i);
//             }
//         };

//         vector<int> psev(n, 0);
//         function<void()> pse = [&]()
//         {
//             stack<int> st;
//             for (int i = 0; i < n; i++)
//             {
//                 while (!st.empty() && arr[st.top()] > arr[i])
//                 {
//                     st.pop();
//                 }
//                 if (st.empty())
//                 {
//                     psev[i] = -1;
//                 }
//                 else
//                 {
//                     psev[i] = st.top();
//                 }
//                 st.push(i);
//             }
//         };

//         vector<int> ngev(n, 0);
//         function<void()> nge = [&]()
//         {
//             stack<int> st;
//             for (int i = n - 1; i >= 0; i--)
//             {
//                 while (!st.empty() && arr[st.top()] <= arr[i])
//                 {
//                     st.pop();
//                 }
//                 if (st.empty())
//                 {
//                     ngev[i] = n;
//                 }
//                 else
//                 {
//                     ngev[i] = st.top();
//                 }
//                 st.push(i);
//             }
//         };

//         vector<int> pgev(n, 0);
//         function<void()> pge = [&]()
//         {
//             stack<int> st;
//             for (int i = 0; i < n; i++)
//             {
//                 while (!st.empty() && arr[st.top()] < arr[i])
//                 {
//                     st.pop();
//                 }
//                 if (st.empty())
//                 {
//                     pgev[i] = -1;
//                 }
//                 else
//                 {
//                     pgev[i] = st.top();
//                 }
//                 st.push(i);
//             }
//         };

//         // Compute the next/prev smaller/greater values
//         nse();
//         pse();
//         nge();
//         pge();

//         // Got all the four elements
//         map<int, int> mini;
//         map<int, int> maxi;

//         for (int i = n - 1; i >= 0; i--)
//         {
//             mini[arr[i]] += (nsev[i] - i) * 1LL * (i - psev[i]);
//             maxi[arr[i]] += (ngev[i] - i) * 1LL * (i - pgev[i]);
//         }

//         long long ans = 0;
//         for (auto it : maxi)
//         {
//             ans += it.first * 1LL * it.second;
//         }
//         for (auto it : mini)
//         {
//             ans -= it.first * 1LL * it.second;
//         }

//         return ans;
//     }
// };

// int main()
// {
//     // Create an instance of the Solution class
//     Solution solution;

//     // Input the size of the array
//     int n;
//     cout << "Enter the number of elements in the array: ";
//     cin >> n;

//     // Input the elements of the array
//     vector<int> arr(n);
//     cout << "Enter the elements of the array: ";
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> arr[i];
//     }

//     // Call the subArrayRanges function and print the result
//     long long result = solution.subArrayRanges(arr);
//     cout << "The sum of subarray ranges is: " << result << endl;

//     return 0;
// }


// #include<iostream>
// using namespace std;
// int main(){
//     int testcases;
//     cin>>testcases;
    
//     for(int i=0;i<testcases;i++){
//         int ans = 0;
//         int n,x,y;
//         cin>>n>>x>>y;
//         int arr[n];
//         int sum=0;
//         for(int j=0;j<n;j++){
//             cin>>arr[j];
//             sum+=arr[j];
//         }
//         int min=sum-y;
//         int max=sum-x;
//         for(int j=0;j<n-1;j++){
            
//             for(int k=j+1;k<n;k++){
//                 int sum1 = arr[j];
//                 sum1+=arr[k];
//                 if(sum1>=min && sum1<=max){
//                     ans++;
//                     break;
//                 }
//             }
//         }
//         cout << ans<<endl;
//     }
//     return 0;
    
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int testcases;
//     cin >> testcases;
//     for (int i = 0; i < testcases; i++)
//     {
//         int ans = 0;
//         int n, x, y;
//         cin >> n >> x >> y;
//         vector<int> arr(n);
//         int total_sum = 0;
//         for (int j = 0; j < n; j++)
//         {
//             cin >> arr[j];
//             total_sum += arr[j];
//         }
//         int min_sum = total_sum - y;
//         int max_sum = total_sum - x;
//         vector<int> prefix_sum(n + 1, 0);
//         for (int j = 0; j < n; j++)
//         {
//             prefix_sum[j + 1] = prefix_sum[j] + arr[j];
//         }
//         for (int j = 0; j < n; j++)
//         {
//             for (int k = j + 1; k <= n; k++)
//             {
//                 int subarray_sum = prefix_sum[k] - prefix_sum[j];
//                 if (subarray_sum >= min_sum && subarray_sum <= max_sum)
//                 {
//                     ans++;
//                 }
//             }
//         }

//         cout << ans << endl;
//     }
//     return 0;
// }

//fibonacci series
#include <iostream>
using namespace std;
int fibo(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
    return 0;
}
