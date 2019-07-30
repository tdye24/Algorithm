package 树;

import java.util.LinkedList;
import java.util.Queue;

class Node<T extends Comparable<? super T>>{
	T data;
	Node<T> left;
	Node<T> right;
	int height;
	
	public Node(T data) {
		this(data, null, null);
	}
	public Node(T data, Node<T> left, Node<T> right) {
		this.data = data;
		this.left = left;
		this.right = right;
	}
}

public class AVLTree<T extends Comparable<? super T>> {
	Node<T> root;
	int countInsertions;
	int countSingleRotation;
	int countDoubleRotation;
	
	public AVLTree() {
		this.root = null;
		
		this.countInsertions = 0;
		this.countSingleRotation = 0;
		this.countDoubleRotation = 0;
	}
	
	public int height(Node<T> root) {
		return root == null ? -1:root.height;
	}
	
	public boolean insert(T x) {
		try {
			root = insert(x, this.root);
			this.countInsertions ++;
			return true;
		} catch(Exception e) {
			return false; //重复插入同一节点
		}
	}
	
	private Node<T> insert(T x, Node<T> root) throws Exception {
		if(root == null)
			root = new Node<T>(x);
		else if(x.compareTo(root.data) < 0) {
			root.left = insert(x, root.left);
			if(height(root.left) - height(root.right) == 2) {
				if(x.compareTo(root.left.data) < 0) {//必须先判断是否为LL型
					root = LL(root);//LL
					System.out.println("LL");
					this.countSingleRotation ++;
				} else {
					root = LR(root);//LR
					System.out.println("LR");
					this.countDoubleRotation ++;
				}
				
			}
		
		} else if(x.compareTo(root.data) > 0) {
			root.right = insert(x, root.right);
			if(height(root.right) - height(root.left) == 2) { 
				if(x.compareTo(root.right.data) > 0) {//必须先判断是否为RR型
					root = RR(root);//RR
					System.out.println("RR");
					this.countSingleRotation ++;
				} else {
					root = RL(root);//RL
					System.out.println("RL");
					this.countDoubleRotation ++;
				}
			}
		} else {
			throw new Exception("Duplicate value!");
		}
		root.height = Math.max(height(root.left), height(root.right))+1;
		return root;
	}
	
	public Node<T> LL(Node<T> K2) {
		Node<T> K1 = K2.left;
		
		K2.left = K1.right;
		K1.right = K2;
		
		K2.height = Math.max(height(K2.left), height(K2.right)) + 1;
		K1.height = Math.max(height(K1.left), height(K1.right)) + 1;
		
		return K1;
	}
	
	public Node<T> LR(Node<T> K3) {
		K3.left = RR(K3.left);
		return LL(K3);
	}
	
	public Node<T> RR(Node<T> K1) {
		Node<T> K2 = K1.right;
		
		K1.right = K2.left;
		K2.left = K1;
		
		K1.height = Math.max(height(K1.left), height(K1.right)) + 1;
		K2.height = Math.max(height(K2.left), height(K2.right)) + 1;
		
		return K2;
	}
	
	public Node<T> RL(Node<T> K1) {
		K1.right = LL(K1.right);
		return RR(K1);
	}
	
	public void PreOrder(Node<T> root) {
		if(root != null) {
			System.out.print(root.data + " ");
			PreOrder(root.left);
			PreOrder(root.right);
		}
	}
	
	public void InOrder(Node<T> node) {
		if(node != null) {
			InOrder(node.left);
			System.out.print(node.data + " ");
			InOrder(node.right);
		}
	}

	public void PostOrder(Node<T> node) {
		if(node != null) {
			PostOrder(node.left);
			PostOrder(node.right);
			System.out.print(node.data + " ");
		}
	}
	
	public void LevelOrder(Node<T> root) {
		if(root == null) 
			return ;
		Queue<Node<T>> queue = new LinkedList<>();
		queue.add(root);
		while(!queue.isEmpty()) {
			while(!queue.isEmpty()) {
				Node<T> node = queue.poll();
				System.out.print(node.data + " ");
				if(node.left != null) {
					queue.add(node.left);
				} 
				if(node.right != null) {
					queue.add(node.right);
				}		
			}
		}
		
	}
	
	public void makeEmpty() {
		this.root = null;
	}
	
	public boolean isEmpty() {
		return (root == null);
	}
	
	public T findMin() {
		if(isEmpty())
			return null;
		return findMin(this.root).data;
	}
	private Node<T> findMin(Node<T> root) {
		if(root == null)
			return root;
		while(root.left != null)
			root = root.left;
		return root;
	}
	
	public T findMax() {
		if(isEmpty())
			return null;
		return findMax(this.root).data;
	}
	private Node<T> findMax(Node<T> root) {
		if(root == null)
			return root;
		while(root.right != null)
			root = root.right;
		return root;
	}
	
	public void remove(T x) {
		this.root = remove(x, this.root);
	}
	private Node<T> remove(T x, Node<T> root) {
		if(root == null) {
			System.out.println("No such a node in this tree" + " whose data is " + x);
			return null;
		}
		System.out.println("Remove " + x + " from " + root.data + " ...");
		if(x.compareTo(root.data) < 0) {
			root.left = remove(x, root.left);
			if(height(root.right) - height(root.left) == 2) {
				if(root.right.left != null && height(root.right.left) > height(root.right.right))
					root = RL(root);
				else
					root = RR(root);
			}
			
		} else if(x.compareTo(root.data) > 0) {
			root.right = remove(x, root.right);
			if(height(root.left) - height(root.right) == 2) {
				if(root.left.right != null && height(root.left.right) > height(root.left.left))
					root = LR(root);
				else
					root = LL(root);
			}
		} else {
			if(root.left != null && root.right != null) {
				root.data = findMin(root.right).data;
				remove(root.data, root.right);
				
				if(height(root.left) - height(root.right) == 2) {
					if(root.left.right != null && height(root.left.right) > height(root.left.left))
						root = LR(root);
					else
						root = LL(root);
				}
			} else {
				if(root.left == null) 
					root = root.right;
				else if(root.right == null)
					root = root.left;
			}
		}
		if(root == null) 
			return root;
		root.height = Math.max(height(root.left), height(root.right)) + 1;
		return root;
	
	}
	
	public T find(T x) {
		if(this.root == null)
			return null;
		return find(x, this.root) == null ? null:find(x, this.root).data;
	}
	private Node<T> find(T x, Node<T> root) {
		if(root == null) {
			return null;
		}
		if(x.compareTo(root.data) < 0) {
			return find(x, root.left);
		} else if(x.compareTo(root.data) > 0) {
			return find(x, root.right);
		} else {
			return root;
		}
	}
	
	
	public static void main(String[] args) {
		AVLTree<Integer> tree = new AVLTree<Integer>();
	    
	    tree.insert (new Integer(2));
	    tree.insert (new Integer(1));
	    tree.insert (new Integer(4));
	    tree.insert (new Integer(5));
	    tree.insert (new Integer(9));
	    tree.insert (new Integer(3));
	    tree.insert (new Integer(6));
	    tree.insert (new Integer(7));
	    
	    System.out.println("PreOrder");
	    tree.PreOrder(tree.root);
	    System.out.println();
	    
	    System.out.println("InOrder");
	    tree.InOrder(tree.root);
	    System.out.println();
	    
	    System.out.println("PostOrder");
	    tree.PostOrder(tree.root);
	    System.out.println();
	    
	    System.out.println("LevelOrder");
	    tree.LevelOrder(tree.root);
	    System.out.println();
	    
	    System.out.println("Find");
	    System.out.println(tree.find(5));
	    System.out.println(tree.find(100));
	    
	    System.out.println("Remove");
	    tree.remove(5);
	    System.out.println(tree.find(5));
	    tree.LevelOrder(tree.root);
	    
	    
	}
}
