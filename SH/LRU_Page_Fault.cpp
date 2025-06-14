
#include<bits/stdc++.h> 
using namespace std; 


int pageFaults(int pages[], int n, int capacity) 
{ 

	unordered_set<int> s; 

	// To store least recently used indexes 
	// of pages. 
	unordered_map<int, int> indexes; 

	// Start from initial page 
	int page_faults = 0; 
	for (int i=0; i<n; i++) 
	{ 
		// Check if the set can hold more pages 
		if (s.size() < capacity) 
		{ 
			 
			if (s.find(pages[i])==s.end()) 
			{ 
				s.insert(pages[i]); 

				// increment page fault 
				page_faults++; 
			} 

		
			indexes[pages[i]] = i; 
		} 

	 
		else
		{ 
			
			if (s.find(pages[i]) == s.end()) 
			{ 
			
				int lru = INT_MAX, val; 
				for (auto it=s.begin(); it!=s.end(); it++) 
				{ 
					if (indexes[*it] < lru) 
					{ 
						lru = indexes[*it]; 
						val = *it; 
					} 
				} 

				// Remove the indexes page 
				s.erase(val); 

				// insert the current page 
				s.insert(pages[i]); 

				// Increment page faults 
				page_faults++; 
			} 

			// Update the current page index 
			indexes[pages[i]] = i; 
		} 
	} 

	return page_faults; 
} 

// Driver code 
int main() 
{ 
	int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}; 
	int n = sizeof(pages)/sizeof(pages[0]); 
	int capacity = 4; 
	cout << pageFaults(pages, n, capacity); 
	return 0; 
} 
