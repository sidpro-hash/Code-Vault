/*
 *
 *
 * @author SidPro
 * @version 1.0
 *
 * Given a string s, return the longest palindromic substring in s.
 * we can solve this using Manacher's algorithm
 *
 * @see https://cp-algorithms.com/string/manacher.html
*/

class LongestPalindrome {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int best = 1;               // length of best string palindrome 
        int st = 0;                 // starting index of our best string palindrome
        
        
        // for handling odd length palindrome
        
        for(int i = 0; i < n; i++)
        {
            int len = 1;           // because every single character will be a palindrome
            int j = i - 1;        // maintaing ith character as middle of our palindromic string, 
            int k = i + 1;        // we start checking for further left and right side.
            
            while(j >= 0 && k < n && s[j] == s[k])
            {
                j--;
                k++;
                len = len + 2;
            }
            
            if(len > best)
            {
                best = len;
                st = j + 1;
            }
        }
        
        // similarly checking for even length palindromic substring.
        
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i - 1])
            {
                int len = 2;       // since we are taking two elements as middle , we start our length as 2.
                
                int j = i - 2;     // remaing steps are similar as for odd length palindrome.
                int k = i + 1;
                
                while(j >= 0 && k < n && s[j] == s[k])
                {
                    j--;
                    k++;
                    len = len + 2;
                }
                
                if(len > best)
                {
                    best = len;
                    st = j + 1;
                }
            }
        }
        
        return s.substr(st, best);
    }
};