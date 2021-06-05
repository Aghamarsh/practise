class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() >=3)
        {
            int increasing = 1;
            int decreasing = 0;
            
            for(int i = 1; i < arr.size(); i++)
            {
                if(arr[i] == arr[i-1])
                    return 0;
                
                if(increasing && arr[i] < arr[i-1])
                {
                    if(i == 1)
                        return 0;
                    
                    decreasing = 1;
                    increasing = 0;
                }
                
                if(decreasing && arr[i] > arr[i-1])
                    return 0;
                
            }
            
            if(decreasing && !increasing)
                return 1;
            else
                return 0;
        }
        
        return 0;
    }
};