package 树;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class TreeNode {
	private int data;
	private TreeNode left;
	private TreeNode right;
	public TreeNode(int data, TreeNode left, TreeNode right) {
		this.data = data;
		this.left = left;
		this.right = right;
	}
	
	public int getData() {
		return this.data;
	}
	
	public void setData(int data) {
		this.data = data;
	}
	
	public TreeNode getLeft() {
		return this.left;
	}
	
	public void setLeft(TreeNode left) {
		this.left = left;
	}
	
	public TreeNode getRight() {
		return this.right;
	}
	
	public void setRight(TreeNode right) {
		this.right = right;
	}
}


public class BinaryTree {
	private TreeNode root;
	
	/*
	 * 二叉树的创建
	 */
	public BinaryTree() {}
	public BinaryTree(TreeNode root) {
		this.root = root;
	}
	public TreeNode getRoot() {
		return this.root;
	}
	/*
	 * 二叉树的清空
	 */
	public void clear() {
		clear(root);
	}
	private void clear(TreeNode node) {
		if(node != null) {
			clear(node.getLeft());
			clear(node.getRight());
			node = null;
		}
	}
	/*
	 * 判断二叉树是否为空
	 */
	public boolean isEmpty() {
		return root == null;
	}
	/*
	 * 求二叉树的高度
	 */
	public int heigh() {
		return heigh(root);
	}
	private int heigh(TreeNode node) {
		if(node == null) {
			return 0;
		}
		int leftheigh = heigh(node.getLeft());
		int rightheigh = heigh(node.getRight());
		return leftheigh > rightheigh ? (leftheigh+1):(rightheigh+1);
	}
	/*
	 * 求二叉树的节点数
	 */
	public int size() {
		return size(root);
	}
	private int size(TreeNode node) {
		if(node == null) {
			return 0;
		}
		return 1+size(node.getLeft())+size(node.getRight());
	}
	/*
	 * 返回左右子树
	 */
	public TreeNode getLeftTree(TreeNode node) {
		return node.getLeft();
	}
	public TreeNode getRightTree(TreeNode node) {
		return node.getRight();
	}
	/*
	 * 二叉树的插入
	 */
	public void insertLeft(TreeNode parent, TreeNode newnode) {
		parent.setLeft(newnode);
	}
	public void insertRight(TreeNode parent, TreeNode newnode) {
		parent.setRight(newnode);
	}
	/*
	 * 二叉树的遍历
	 */
	/*
	 * 先根遍历
	 */
	public void PreOrder(TreeNode node) {
		if(node != null) {
			System.out.println(node.getData());
			PreOrder(node.getLeft());
			PreOrder(node.getRight());
		}
	}
	/*
	 * 中根遍历
	 */
	public void InOrder(TreeNode node) {
		if(node != null) {
			InOrder(node.getLeft());
			System.out.println(node.getData());
			InOrder(node.getRight());
		}
	}
	/*
	 * 后根遍历
	 */
	public void PostOrder(TreeNode node) {
		if(node != null) {
			PostOrder(node.getLeft());
			PostOrder(node.getRight());
			System.out.println(node.getData());
		}
	}
	public static void BFSWithQueue(TreeNode root) {
	    Queue<TreeNode> queue = new LinkedList<>();
	    if (root != null)
	        queue.add(root);
	    while (!queue.isEmpty()) {
	        TreeNode treeNode = queue.poll();
	        System.out.print(treeNode.getData() + " ");
	        if (treeNode.getLeft() != null)
	            queue.add(treeNode.getLeft());
	        if (treeNode.getRight() != null)
	            queue.add(treeNode.getRight());
	    }
	}
	
	public static void DFSWithStack(TreeNode root) {
	     if (root == null)
	         return;
	     Stack<TreeNode> stack = new Stack<>();
	     stack.push(root);
	 
	     while (!stack.isEmpty()) {
	         TreeNode treeNode = stack.pop();
	 
	         System.out.print(treeNode.getData()+ " ");
	             
	         if (treeNode.getRight() != null)
	             stack.push(treeNode.getRight());
	 
	         if (treeNode.getLeft() != null)
	             stack.push(treeNode.getLeft());
	     }
	}
	
	public static void CalLevel(TreeNode root) {
		if(root == null) 
			return ;
		Queue<TreeNode> queue = new LinkedList<>();
		Queue<TreeNode> tempQueue = new LinkedList<>();
		queue.add(root);
		while(!queue.isEmpty()) {
			int sum = 0;
			while(!queue.isEmpty()) {
				tempQueue.add(queue.poll());
			}
			while(!tempQueue.isEmpty()) {
				TreeNode node = tempQueue.poll();
				sum += node.getData();
				if(node.getLeft() != null) {
					queue.add(node.getLeft());
				} 
				if(node.getRight() != null) {
					queue.add(node.getRight());
				}
				
				
			}
			System.out.println(sum);
		}
		
	}
	
	
	public static void main(String[] args) {
		TreeNode node4 = new TreeNode(4, null, null);
		TreeNode node5 = new TreeNode(5, null, null);
		TreeNode node2 = new TreeNode(2, node4, node5);
		TreeNode node6 = new TreeNode(6, null, null);
		TreeNode node7 = new TreeNode(7, null, null);
		TreeNode node3 = new TreeNode(3, node6, node7);
		TreeNode root = new TreeNode(1, node2, node3);
		System.out.println("BFSWithQueue");
		BFSWithQueue(root);
		System.out.println();
		System.out.println("DFSWithStack");
		DFSWithStack(root);
		System.out.println();
		System.out.println("CalLevel");
		CalLevel(root);

	}

}

