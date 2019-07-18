package 背包九讲;

import java.util.*;
import java.io.*;
public class Knapsack3_1 {
	public static final int MAX = 200;
	static int[] f = new int[MAX];
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int V = sc.nextInt();
		for(int i=0; i<N; i++) {
			int w, v, s;//体积v，价值w，数量s
			v = sc.nextInt();
			w = sc.nextInt();
			s = sc.nextInt();
			for(int j=V; j>=v; j--) {
				for(int k=1; k<=s && k*v <= j; k++) {
					f[j] = Math.max(f[j], f[j-k*v] + k*w);
				}
			}
			
		}
		System.out.println(f[V]);
		

	}

}
