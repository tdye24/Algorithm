package ±³°ü¾Å½²;

import java.util.Scanner;
import java.io.BufferedInputStream;

public class Knapsack1 {
    
    public static void main(String[] args){
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        int N = sc.nextInt();
        int V = sc.nextInt();
        int[] v = new int[N+1];
        int[] w = new int[N+1];
        int[][] f = new int[N+1][V+1];
        f[0][0] = 0;
        for(int i=1; i<=N; i++) {
            v[i] = sc.nextInt();
            w[i] = sc.nextInt();
        }
        
        for(int i=1; i<=N; i++) {
            for(int j=0; j<=V; j++) {
                f[i][j] = f[i-1][j];
                if(j >= v[i]) {
                    f[i][j] = Math.max(f[i][j], f[i-1][j-v[i]] + w[i]);
                }
            }
            
        }
        int ans = 0;
        for(int i=0; i<=V; i++) {
            ans = Math.max(ans, f[N][i]);
        }
        System.out.println(ans);
    }
}