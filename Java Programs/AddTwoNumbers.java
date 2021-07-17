
/**
 *
 *
 *
 * @author SidPro
 * @version 1.0
 * 
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order, and each of their nodes contains a single digit. 
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ptr = new ListNode(34,null);
        ListNode ans = ptr;
        int r =0;
        while(l1!=null && l2!=null){
            
            int k = l1.val + l2.val + r;
            r=0;
            if(k>9){
                r = k/10;
                k = k%10;
            }
            
            ListNode temp = new ListNode(k,null);
            ptr.next = temp;
            ptr = temp;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1!=null){
            int k = l1.val + r;
            r=0;
            if(k>9){
                r = k/10;
                k = k%10;
            }
            ListNode temp = new ListNode(k,null);
            ptr.next = temp;
            ptr = temp;
            l1 = l1.next;
        }
        while(l2!=null){
            int k = l2.val + r;
            r=0;
            if(k>9){
                r = k/10;
                k = k%10;
            }
            ListNode temp = new ListNode(k,null);
            ptr.next = temp;
            ptr = temp;
            l2 = l2.next;
        }
        if(r>0){
            ListNode temp = new ListNode(r,null);
            ptr.next = temp;
            ptr= temp;
        }
        ans = ans.next;
        return ans;
    }
}