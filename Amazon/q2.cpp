class Solution {
public:
    int longestMountain(vector<int>& a) {
        int i,ans=0,c=0,n=a.size();
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1])  //If nos are same then we skip it
                c=0;            
            else if(a[i]>a[i-1]) //if next>prev we increase the count
                c++;
            //Else we first calculate count of next<prev and update the final ans
            else if(c>0)           
            {
                    while(i<n and a[i]<a[i-1])
                    {
                        c++; i++;
                    }
                    ans = max(ans,c+1);
                    c=0 ;i--;
            }
        }
        return ans;
    }
};