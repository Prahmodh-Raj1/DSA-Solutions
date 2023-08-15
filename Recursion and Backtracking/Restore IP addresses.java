//Problem link: https://leetcode.com/problems/restore-ip-addresses/ 
//TC: O(3^4)
class Solution {
    private boolean isValid(String check){
        if(check.charAt(0)=='0') return false;
        int curval = Integer.parseInt(check);
        if(curval<0 || curval>255) return false;
        return true;
    }
    private void helper(String s,int ind,int partitions,String ans,List<String> result){
        if(ind==s.length() || partitions==4){
            if(ind==s.length() && partitions==4){
                result.add(ans.substring(0,ans.length()-1));
                
            }
            return;
        }
        helper(s,ind+1,partitions+1,ans+s.charAt(ind)+'.',result);
        if(ind+2<=s.length() && isValid(s.substring(ind,ind+2))){
            helper(s,ind+2,partitions+1,ans+s.substring(ind,ind+2)+'.',result);
        }
        if(ind+3<=s.length() && isValid(s.substring(ind,ind+3))){
            helper(s,ind+3,partitions+1,ans+s.substring(ind,ind+3)+'.',result);
        }
    }
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<String>();
        helper(s,0,0,"",ans);
        return ans;
    }
}
