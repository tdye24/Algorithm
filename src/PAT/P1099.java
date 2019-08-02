package PAT;

import java.util.*;
import java.io.*;

class Item {
	int data;
	int left;
	int right;
	
	public Item(int left, int right) {
		this.left = left;
		this.right = right;
	}
}
public class P1099 {
	static int id = 0;
	static Item[] nodes = new Item[100];
	static int[] arr;
	static int count = 0;
	
	public static void InOrder(int index) {
		if(index != -1) {
			InOrder(nodes[index].left);
			nodes[index].data = arr[id];
			id ++;
			InOrder(nodes[index].right);
		}
	}
	
	public static void LevelOrder(int index) {
		if(index == -1) 
			return ;
		Queue<Item> queue = new LinkedList<>();
		queue.add(nodes[index]);
		
		while(!queue.isEmpty()) {
			Item node = queue.poll();
			if(count == 0) 
				System.out.print(node.data);
			else
				System.out.print(" " + node.data);
			if(node.left != -1) {
				queue.add(nodes[node.left]);
			} 
			if(node.right != -1) {
				queue.add(nodes[node.right]);
			}	
			count ++;
		}
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		
		for(int i=0; i<N; i++) {
			nodes[i] = new Item(sc.nextInt(), sc.nextInt());
		}
		arr = new int[N];
		for(int i=0; i<N; i++) {
			arr[i] = sc.nextInt();
		}
		sc.close();
		Arrays.sort(arr);
		InOrder(0);
		LevelOrder(0);
	}
}
