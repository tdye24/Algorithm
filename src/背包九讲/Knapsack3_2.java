package 背包九讲;

import java.util.*;
import java.io.*;
public class Knapsack3_2 {
	public static int[] f = new int[2010];
	class Good {
		int v;//分堆后，每一堆的体积
		int w;//分堆后，每一堆的价值
		
		public Good(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}
	public static ArrayList<Good> goods = new ArrayList<Good>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int V = sc.nextInt();
		
		for(int i=0; i<N; i++) {
			int v = sc.nextInt();
			int w = sc.nextInt();
			int s = sc.nextInt();
			for(int k=1; k<=s; k *= 2) {
				goods.add(new Knapsack3_2().new Good(k*v, k*w));
				s -= k;
			}
			if(s>0) {
				goods.add(new Knapsack3_2().new Good(s*v, s*w));
			}
			
		}
		for(Good good: goods) {
			for(int j=V; j>=good.v; j--) {
				f[j] = Math.max(f[j], f[j-good.v] + good.w);
			}
		}
		System.out.println(f[V]);
	}
}
