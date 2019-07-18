package 单调队列;

import java.util.*;
import java.io.*;
public class P01 {
	class Node {
		int id;
		int value;
		public Node(int id, int value) {
			this.id = id;
			this.value = value;
		}
	}
	public static int[] a = new int[1024];
	
	public static void max(int[] a, int n, int k) {
		Deque<Node> queue = new LinkedList<Node>();
		Node node = null;
		for(int i=0; i<n; i++) {
			node = new P01().new Node(i, a[i]);
			if(queue.isEmpty()) {
				queue.offerLast(node);
			} else {
				if(a[i] <= queue.peekLast().value) {
					queue.offerLast(node);
				} else {
					while(!queue.isEmpty() && a[i] > queue.peekLast().value) {
						queue.pollLast();
					}
					queue.offerLast(node);
				}
				if(queue.peekFirst().id + k <= i) {
					queue.pollFirst();
				}
			} 
			if(i >= k-1) {
				System.out.print(queue.peekFirst().value + " ");
			}
			
		}
		if(n < k) {
			System.out.print(queue.peekFirst().value);
		}
	}
	
	public static void min(int[] a, int n, int k) {
		Deque<Node> queue = new LinkedList<Node>();
		Node node = null;
		for(int i=0; i<n; i++) {
			node = new P01().new Node(i, a[i]);
			if(queue.isEmpty()) {
				queue.offerLast(node);
			} else {
				if(a[i] >= queue.peekLast().value) {
					queue.offerLast(node);
				} else {
					while(!queue.isEmpty() && a[i] < queue.peekLast().value) {
						queue.pollLast();
					}
					queue.offerLast(node);
				}
				if(queue.peekFirst().id + k <= i) {
					queue.pollFirst();
				}
			} 
			if(i >= k-1) {
				System.out.print(queue.peekFirst().value + " ");
			}
		}
		if(n < k) {
			System.out.print(queue.peekFirst().value);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		int k = sc.nextInt();
		for(int i=0; i<n; i++) {
			a[i] = sc.nextInt();
		}
		min(a, n, k);
		System.out.println("");
		max(a, n, k);
		

	}

}
