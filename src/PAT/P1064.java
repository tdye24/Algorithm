package PAT;

import java.util.*;
import java.io.*;
class Tuple {
	int low;
	int up;
	public Tuple(int low, int up) {
		this.low = low;
		this.up = up;
	}
}
public class P1064 {
	public static Queue<Tuple> queue = new LinkedList<>();
	public static int N;
	public static int num;
	public static List<Integer> a = new ArrayList<>(); 
	public static void solve() {
		while(!queue.isEmpty()) {
			Tuple tuple = queue.poll();
			int l = tuple.low;
			int r = tuple.up;
			if(l == r) {
				num ++;
				if(num != N) {
					System.out.print(a.get(l) + " ");
				} else {
					System.out.print(a.get(l));
				}
				continue ;
			}
			int k = r - l + 1;
			int t = 1;
			for( ; ;t++) {
				if(Math.pow(2, t)-1 <= k && k <=Math.pow(2, t+1)-1) {
					break ;
				}
			}
			int m = (int) (k - Math.pow(2, t) + 1);
			int leftNum = 0;
			int rightNum = 0;
			if(m <= Math.pow(2, t-1)) {
				leftNum = (int) (Math.pow(2, t-1) -1 + m);
				rightNum = (int) (Math.pow(2, t-1)) - 1;
			} else {
				leftNum = (int) (Math.pow(2, t) -1);
				rightNum = m -1;
			}
			num ++;
			if(num != N) {
				System.out.print(a.get(l + leftNum) + " ");
			} else {
				System.out.print(a.get(l + leftNum));
			}
			if(l <= l+leftNum-1)
				queue.add(new Tuple(l, l+leftNum-1));
			if(r-rightNum+1 <= r)
				queue.add(new Tuple(r-rightNum+1, r));
		}
		
	}
	public static void print() {
		for(Integer item:a) {
			System.out.println(item);
		}
	}

	public static void main(String[] args) {	
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		N = sc.nextInt();
		for(int i=0; i<N; i++) {
			a.add(sc.nextInt());
		}
		Collections.sort(a);
		queue.add(new Tuple(0, N-1));
		solve();
	}

}
