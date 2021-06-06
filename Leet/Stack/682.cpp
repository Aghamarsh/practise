#include <bits/stdc++.h>
using namespace std;

int sum_of_vec(vector<int> ar)
{
    int sum = 0;
    
    for(int i =0; i<ar.size(); i++)
    {
        sum += ar[i];
    }
    
    return sum;
}
    
int calPoints(vector<string>& ops) {
    vector<int> st;
    
    for(int i=0; i < ops.size(); i ++)
    {
        if(isdigit(ops[i][0]) || ops[i][0] == '-')
        {
            stringstream str(ops[i]);
            
            int num ; 
            str >> num;
            
            st.push_back(num);
        }
        else if(ops[i][0] == 'C')
        {
            st.pop_back();
        }
        else if(ops[i][0] == 'D')
        {
            st.push_back(2 * st[st.size() - 1]);
        }
        else if(ops[i][0] == '+')
        {
            int size = st.size();
            int a = st[size - 1];
            int b = st[size - 2];
            
            st.push_back(a+b);
        }
    }
    
    return sum_of_vec(st);
}

int main()
{
    vector<string> op{"5", "2", "C", "D", "+"};
    int ret = calPoints(op);
    cout << ret << endl;
}

