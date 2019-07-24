package ±³°ü¾Å½²;

import java.util.Scanner;
import java.io.BufferedInputStream;

public class Knapsack0_1 {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int N = sc.nextInt();
        int V = sc.nextInt();
        int[] v = new int[N+1];
        int[] w = new int[N+1];
        int[] f = new int[V+1];
        f[0] = 0;
        for(int i=1; i<=N; i++) {
            v[i] = sc.nextInt();
            w[i] = sc.nextInt();
        }
        
        for(int i=1; i<=N; i++) {
            for(int j=V; j>=v[i]; j--) {
            	f[j] = Math.max(f[j], f[j-v[i]] + w[i]);
            }
            
        }
        
        System.out.println(f[V]);
    }
}