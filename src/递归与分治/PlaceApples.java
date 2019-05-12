package 递归与分治;

import java.util.ArrayList;
import java.util.Collections;

public class PlaceApples {
	/*
	 * 把M个同样的苹果放在N的同样的盘子里，允许有的盘子空着不放，问共有多少种不同的放法（注：5、1、1和1、1、5是同一种放法）*/
	public int M;
	public int N;
	public ArrayList<Integer> arr;
	public ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
	
	public PlaceApples(int M, int N) {
		this.M = M;
		this.N = N;
		this.arr = new ArrayList<Integer>();
		for(int i=0; i<N; i++) {
			arr.add(i, 0);
		}
	}
	
	public void printArray() {
		for(int i=0; i<list.size(); i++) {
			for(int j=0; j<this.N; j++) {
				System.out.print(list.get(i).get(j) + " ");
			}
			System.out.println("");
		}
		
	}
	
	public boolean isValid(ArrayList<Integer> arr) {
		
		for(int i=0; i<list.size(); i++) {
			if(list.get(i).equals(arr)) {
				return false;
			}
		}
		
		return true;
	}
	
	public void place(int m, int n) {
		if(m == 0) {
			ArrayList<Integer> temp = new ArrayList<Integer>();
			for(int k=0; k<arr.size(); k++) {
				temp.add(k, arr.get(k));
			}
			Collections.sort(temp);
			if(isValid(temp)) {
				list.add(temp);
			}
			
			return ;
		} else if(m != 0 && n == 0) {
			return ;
		}
		for(int i=0; i<=m; i++) {
			int temp = arr.get(n-1); 
			arr.set(n-1, i);
			place(m-i, n-1);
			arr.set(n-1, temp);
		}
	}
	
	public void solve() {
		place(this.M, this.N);
		System.out.println("共有" + this.list.size() + "种方案");
		printArray();
	}
	
	
	
	public static void main(String[] args) {
		PlaceApples placeApples = new PlaceApples(7, 3);
		
		placeApples.solve();

	}

}
