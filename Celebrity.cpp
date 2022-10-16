class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    
    int knows(vector<vector<int>> & M, int a, int b){
        return M[a][b];
    }
    
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a= st.top();
            st.pop();
            int b= st.top();
            st.pop();
            if(knows(M,a,b))st.push(b);     //b is candidate for calebrity but a is not 
            else st.push(a);                    
        }
        
        int c=st.top();            //it is possible candidate
        
        for(int i=0;i<n;i++){
            if(i!=c && (knows(M,c,i) || !knows(M,i,c)))    
                return -1;
        }
        return c;
        
    }
};
  
int main(){
  	int t;
  	cin>>t;

  	while(t--){
  		int n;
  		cin>>n;
  		 vector<vector<int>> M(n, vector<int> (n,0));
  		for(int i=0;i<n;i++){
  			for(int j=0;j<n;j++){
             cin>>M[i][j];
        }
  		}

  		solution obj;
  		cout<<obj.celebrity(M,n)<<endl;
  	}


    return 0;
}
  

  
  
  
