
// Sample code to perform I/O:
// https://www.youtube.com/watch?v=GTJr8OvyEVQ
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
#include <iostream>

using namespace std;

void computeLPS(string pat,int M,int *lps){
    //length of the previos longest prefix suffix
    int len = 0;
    lps[0] = 0; // lps[0] is always 0
    
    //the loop calculates lps[i] for i = 1 to M-1
    int i= 1;
    while(i < M){
        if(pat[i] == pat[len]){
            ++len;
            lps[i] = len;
            ++i;
        }
        else{ // (pat[i]!=pat[len])
            if(len != 0){
                len = lps[len - 1];
            }
            else{ // if len=0
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
  
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
  
    // Preprocess the pattern (calculate lps[] array)
    computeLPS(pat, M, lps);
  
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
int main() {
	string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}


// Write your code here