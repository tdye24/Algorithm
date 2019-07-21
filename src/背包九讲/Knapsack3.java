package 背包九讲;

import java.util.*;
import java.io.*;
public class Knapsack3 {
	public static final int MAX = 20024;
	static int[] dp = new int[MAX];
	static int[] f = new int[MAX];
	static int[] monotone_queue = new int[MAX];
	static int[] S = new int[MAX];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int V = sc.nextInt();
		for(int i=1; i<=N; i++) {
			int w, v, s;//体积v，价值w，数量s
			v = sc.nextInt();
			w = sc.nextInt();
			s = sc.nextInt();
			for(int j=0; j<v; j++) {//遍历余数
				int head = 1, tail = 0;
				for(int k=0; k*v+j <= V; k++) {
					int pro = f[k*v+j] - k * w;
					while(head <= tail && pro >= monotone_queue[tail]) 
						tail--;
					S[++tail] = k;
					monotone_queue[tail] = pro;
					f[k*v+j] = monotone_queue[head] + k * w;
					while(s < S[tail] - S[head] + 1) 
						head++;
				}
			}
			
		}
		System.out.println(f[V]);
	}

}
