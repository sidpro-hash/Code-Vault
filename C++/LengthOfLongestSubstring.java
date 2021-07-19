
/*
 *
 *
 * @author SidPro
 * @version 1.0
 *
 * Given a string s, find the length of the longest substring without repeating characters.
*/

class LengthOfLongestSubstring {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> seen = new HashSet<>(); // HashSet to store unique characters
        int n = s.length();
        int j=0,max=0;
        for(int i=0;i<n;++i){
            char ch = s.charAt(i);
            while(seen.contains(ch)){  // if it's character is there than remove from strting index of substring j.
                seen.remove(s.charAt(j++)); // ex. HashSet contains "abc" and 'b' encounter than remove from 'a' to 'b'.
            }
            seen.add(ch);
            max = Math.max(max,i-j+1); 
        }
        return max; // return max length
    }
}