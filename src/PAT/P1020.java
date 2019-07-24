package PAT;

import java.util.*;
import java.io.*;

class Tuple4 {
	public int left;
	public int right;//postorder上下限
	public int low;
	public int up;//inorder上下限
	public Tuple4(int left, int right, int low, int up) {
		this.left = left;
		this.right = right;
		this.low = low;
		this.up = up;
	}
}
public class P1020 {
	static final int MAX = 42;
	static List<Integer> postorder = new ArrayList<>();
	static List<Integer> inorder = new ArrayList<>();
	static Queue<Tuple4> queue = new LinkedList<>();
	static int N;
	static int sum;
	static void solve() {
		Tuple4 current ;
		int root ;
		boolean flag ;//有子树是否为空
		while(!queue.isEmpty()) {
			flag = true;
			current = queue.poll();//(0,6,0,6)
			if(current.low > current.up) 
				continue ;
			if(current.low == current.up) {
				sum ++;
				if(sum == 1) {
					System.out.print(inorder.get(current.up));
				} else {
					System.out.print(" " + inorder.get(current.up));
				}
				continue ;
			}
			root = postorder.get(current.right);//4
			sum ++;
			if(sum == 1) {
				System.out.print(root);
			} else {
				System.out.print(" " + root);
			}
			int id = findid(root);
			for(int i=current.left; i<current.right; i++) {
				if(findid(postorder.get(i)) > id) {
					flag = false;
					Tuple4 left = new Tuple4(current.left, i-1, current.low, id-1);//(0,2,0,2)
					Tuple4 right = new Tuple4(i, current.right-1, id+1, current.up);//(3,5,4,6)
					queue.offer(left);
					queue.offer(right);
					break ;
				}
			}
			if(flag) {
				// 右子树为空
				Tuple4 left = new Tuple4(current.left, current.right-1, current.low, current.up-1);//(0,2,0,2)
				queue.offer(left);	
			}
			
		}
	}
	
	static int findid(int val) {
		for(int i=0; i<inorder.size(); i++) {
			if(inorder.get(i) == val) 
				return i;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		N = sc.nextInt();
		for(int i=0; i<N; i++) {
			postorder.add(sc.nextInt());
		}
		for(int i=0; i<N; i++) {
			inorder.add(sc.nextInt());
		}
		queue.add(new Tuple4(0, N-1, 0, N-1));
		solve();
		
		sc.close();
	}

}
