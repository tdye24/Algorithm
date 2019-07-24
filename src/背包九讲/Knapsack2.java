package ±³°ü¾Å½²;

import java.util.*;
import java.io.*;
public class CompleteKnapsack {
	public static final int  MAX = 1024;
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int V = sc.nextInt();
		int[] w = new int[MAX];
		int[] v = new int[MAX];
		int[] f = new int[MAX];
		for(int i=1; i<=N; i++) {
			v[i] = sc.nextInt();
            w[i] = sc.nextInt();
		}
		
		for(int i=1; i<=N; i++) {
            for(int j=v[i]; j<=V; j++) {
            	f[j] = Math.max(f[j], f[j-v[i]] + w[i]);
            }
        }
        
		
        System.out.println(f[V]);
	}
}
