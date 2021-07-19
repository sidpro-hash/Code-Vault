/*
 *
 *
 * @author SidPro
 * @version 1.0
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
*/

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = strs.size();
        string prefix = strs[0];
        for(int i=0;i<l;++i){
            int l1 = prefix.length();
            int l2 = strs[i].length();
            string temp = "";
            for(int j=0,k=0;j<l1 && k<l2;++k,++j){
                if(prefix[j]==strs[i][k]){
                    temp+=prefix[j];
                }
                else break;
            }
            prefix=temp;
        }
        return prefix;
    }
};