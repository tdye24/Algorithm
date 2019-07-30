package PAT;

import java.util.*;
import java.io.*;

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

public class P1066<T extends Comparable<? super T>> {
	Node<T> root;
	
	public P1066() {
		this.root = null;
	}
	
	public int height(Node<T> root) {
		return root == null ? -1:root.height;
	}
	
	public boolean insert(T x) {
		try {
			root = insert(x, this.root);
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
				} else {
					root = LR(root);//LR
				}
			}
		
		} else if(x.compareTo(root.data) > 0) {
			root.right = insert(x, root.right);
			if(height(root.right) - height(root.left) == 2) { 
				if(x.compareTo(root.right.data) > 0) {//必须先判断是否为RR型
					root = RR(root);//RR
				} else {
					root = RL(root);//RL		
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
			System.out.println(root.data + " ");
			PreOrder(root.left);
			PreOrder(root.right);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		P1066<Integer> tree = new P1066<Integer>();
		int n = sc.nextInt();
		for(int i=0; i<n; i++) {
			tree.insert(sc.nextInt());
		}
		sc.close();
	    System.out.println(tree.root.data);
	}

}
