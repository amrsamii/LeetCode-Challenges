/**
This algorithm finds the maximum subarray sum in a given array. the naive approach to solve this problem is to use brute force which will be O(n^2), but this algorithm solve the problem in O(n)
*/

int find_max_subarray(vector<int> array) {
 	int max_current = array[0];
	int max_global  = array[0];

	for(int i=1;i<array.size();i++) {
		max_current = max(array[i],array[i]+max_current);
		if(max_current > max_global)
			max_global = max_current;
	}
	
	return max_global;
}
