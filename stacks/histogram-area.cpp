/*

 The log
 
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
    //code
    int t;
    cin>>t;
    while(t>0){
        
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        stack<int> s1;
        int top, area, maxArea;
        top = area = maxArea = -1;
        int i;
        for(i=0;i<n;i++){
            if(s1.empty()){
                s1.push(i);
            }
            else{
                if(a[i] > a[s1.top()]){
                    s1.push(i);
                }
                else{
                    while((a[i] <= a[s1.top()]) && (!s1.empty())){
                        
                        int top = a[s1.top()];
                        s1.pop();
                        
                        if(s1.empty()){
                            area = top*i;
                        }
                        else{
                            area = top*(i - s1.top() - 1);
                        }
                        
                        if(area > maxArea)
                            maxArea = area;
                        
                        if(s1.empty())
                            break;
                    }
                    s1.push(i);
                }
            }
        }
        
        while(!s1.empty()){
            int top = a[s1.top()];
            
            
            if(s1.empty()){
                area = top*i;
            }
            else{
                area = top*(i - s1.top() - 1);
            }
            
            if(area > maxArea)
                maxArea = area;
        }
        
        cout<<maxArea<<endl;
        
        t--;
    }
    return 0;
}

