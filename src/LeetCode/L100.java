package LeetCode;
class TreeNode {
	int val;
	TreeNode left, right;
}

public class L100 {
	public static boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null) 
        	return true;
        if(p != null && q != null && p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right))
        	return true;
        return false;
        
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
