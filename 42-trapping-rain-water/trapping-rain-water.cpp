class Solution {
public:
int rainwater(vector<int> &height) {
    int n = height.size();
    vector<int> leftmax(n) , rightmax(n);

    // calculating the leftmax building for every given building 
    // 0th index wali ke leftmei mitti hai
    leftmax[0]= 0;
    int leftkisabsebadibuilding = height[0];

    // finding the left side max height building 
    for(int i= 1 ; i<n; i++){
        leftmax[i] = leftkisabsebadibuilding;
        leftkisabsebadibuilding = max(leftkisabsebadibuilding , height[i]);

    }
//     for(int i=0; i<n; i++){

//         cout<<leftmax[i]<<" ";
// }
// cout<< endl;

    rightmax[n-1] = 0;
    int rightkisabsebadibuilding = height[n-1];
    // finding the Right side max height building 
    for(int i=n-2 ; i>=0 ; i--){
        rightmax[i] = rightkisabsebadibuilding;
        rightkisabsebadibuilding = max(rightkisabsebadibuilding, height[i]);
}
// for(int i=0; i<n; i++){

//     cout<<rightmax[i]<<" ";
// }


// for(int i=0; i<n; i++){

//     cout<<min(leftmax[i] , rightmax[i])<<" ";
// }
//     cout<<endl;

    int ans =0;
    for(int i=0; i<n; i++){

         int kitnapaaniruka=min(leftmax[i] , rightmax[i]) - height[i];
         if(kitnapaaniruka>0){
            ans +=kitnapaaniruka;
         }
    }
        return ans;
}
    int trap(vector<int>& height) {
        int ans= rainwater(height);
        return ans;
        
    }
};