package Ì°ÐÄ·¨;

import java.util.ArrayList;
import java.util.Collections;

public class FenceRepair {
	public int N;
	public ArrayList<Integer> arraylist = new ArrayList<Integer>();
	public FenceRepair(int N, int[] L) {
		this.N = N;
		for(int i=0; i<N; i++) {
			arraylist.add(L[i]);
		}
	}
	
	public void print() {
		Collections.sort(arraylist);
		for(int i=0; i<arraylist.size(); i++) {
			System.out.println(arraylist.get(i));
		}
	}
	
	public int solve() {
		int ans = 0;
		Collections.sort(arraylist);
		while(arraylist.size() != 1) {
			arraylist.set(1, arraylist.get(0) + arraylist.get(1));
			ans += arraylist.get(1);
			arraylist.remove(0);
			Collections.sort(arraylist);
		}
		
		return ans;
	}
	
	
	
	public static void main(String[] args) {
		int N = 3;
		int[] L = {8, 5, 8};
		FenceRepair fencerepair = new FenceRepair(N, L);
		System.out.println(fencerepair.solve());

	}

}
