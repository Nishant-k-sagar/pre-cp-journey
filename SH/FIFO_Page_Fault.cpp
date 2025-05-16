#include<bits/stdc++.h> 
using namespace std; 
  

int pageFaults(int pages[], int n, int capacity) 
{ 
    
    unordered_set<int> s; 
  
    
    queue<int> indexes; 
  
    // Start from initial page 
    int page_faults = 0; 
    for (int i=0; i<n; i++) 
    { 
        
        if (s.size() < capacity) 
        { 
            
            if (s.find(pages[i])==s.end()) 
            { 
                // Insert the current page into the set 
                s.insert(pages[i]); 
  
                // increment page fault 
                page_faults++; 
  
                
                indexes.push(pages[i]); 
            } 
        } 
  
       
        else
        { 
            // Check if current page is not already 
            // present in the set 
            if (s.find(pages[i]) == s.end()) 
            { 
              
                int val = indexes.front(); 
                  
                // Pop the first page from the queue 
                indexes.pop(); 
  
                // Remove the indexes page from the set 
                s.erase(val); 
  
                // insert the current page in the set 
                s.insert(pages[i]); 
  
                // push the current page into 
                // the queue 
                indexes.push(pages[i]); 
  
                // Increment page faults 
                page_faults++; 
            } 
        } 
    } 
  
    return page_faults; 
} 
  
// Driver code 
int main() 
{ 
    int pages[] = {1, 3, 0, 3, 5, 6, 3}; 
    int n = sizeof(pages)/sizeof(pages[0]); 
    int capacity = 3; 
    cout << pageFaults(pages, n, capacity); 
    return 0; 
} 