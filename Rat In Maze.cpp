//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
    
    void helper(vector<vector<int>> &mat,int r, int c, string path,vector<string> &ans,vector<vector<bool>> &vis){
        // base case
        int n = mat.size();
        if(r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || vis[r][c]==true){
            return;
        }
        
        if(r== n-1 && c == n-1){
            ans.push_back(path);
            return;
        }
        
        // marked as visited
        vis[r][c] = true;
        
        helper(mat,r+1,c,path+"D",ans,vis);//down
        helper(mat,r-1,c,path+"U",ans,vis);//up
        helper(mat,r,c-1,path+"L",ans,vis);//left
        helper(mat,r,c+1,path+"R",ans,vis);//right
        
        // marked as false back tracking
        vis[r][c] = false;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        vector<string> ans;
        int n = mat.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        string path = "";
        helper(mat,0,0,path,ans,visited);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
