#include<bits/stdc++.h>

/*
    Problems Link : https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0
    TC - O(n)
    SC - O(1)
*/

int frogJump(int n, vector<int> &heights)
{
    int next = 0, nextOfNext = 0, current = 0;
    for(int i=n-2; i>=0; i--){
        current = abs(heights[i]-heights[i+1]) + next;
        if(i+2<n){
            current = min(current, abs(heights[i]-heights[i+2]) + nextOfNext);
        }
        nextOfNext = next;
        next = current;
    }
    return current;
}