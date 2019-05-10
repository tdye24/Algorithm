package 贪心法;

import java.util.ArrayList;
import java.util.Collections;

class Pair implements Comparable<Pair>{
	int start;
	int terminal;
	
	public Pair(int start, int terminal) {
		this.start = start;
		this.terminal = terminal;
	}

	public int compareTo(Pair another) {
		int i = this.terminal > another.terminal ? 1:-1;//升序，-1:1降序
		return i;
	} 
}

public class RangeProblems {
	public static ArrayList<Pair> arraylist = new ArrayList<Pair>();
	
	public RangeProblems(int[] s, int[] t, int n) {
		for(int i=0; i<n; i++) {
			arraylist.add(new Pair(s[i], t[i]));
		}
	}
	
	public int solve() {
		int ans = 0, currentTime = 0;
		for(int i=0; i<arraylist.size(); i++) {
			System.out.println(arraylist.get(i).start + "-" + arraylist.get(i).terminal);
		}
		Collections.sort(arraylist);
		System.out.println("----------按照任务结束时间排序---------");
		for(int i=0; i<arraylist.size(); i++) {
			System.out.println(arraylist.get(i).start + "-" + arraylist.get(i).terminal);
		}
		
		for(int i=0; i<arraylist.size(); i++) {
			if(currentTime<arraylist.get(i).start) {
				ans ++;
				currentTime = arraylist.get(i).terminal; 
			}
		}
		
		return ans;
	}
	
	public static void main(String[] args) {
		int n = 5;
		int[] s = {1, 2, 4, 6, 8};
		int[] t = {3, 5, 7, 9, 10};
		RangeProblems rangeproblems = new RangeProblems(s, t, n);
		System.out.print("最多能参与到" + rangeproblems.solve() + "项工作");
	}

}
