package PAT;

import java.util.*;
import java.io.*;
public class P1009 {
	public static double[] f = new double[1024];
	public static double[] g = new double[2048];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int ex = 0;
		double co = 0;
		
		int Anum = sc.nextInt();
		for(int i=0; i<Anum; i++) {
			ex = sc.nextInt();
			co = sc.nextDouble();
			f[ex] += co;
		}
		
		int Bnum = sc.nextInt();
		for(int i=0; i<Bnum; i++) {
			ex = sc.nextInt();
			co = sc.nextDouble();
			for(int j=0; j<1024; j++) {
				if(f[j] != 0) {
					g[ex+j] += co*f[j];
				}
			}
			
		}
		
		int K = 0;
		for(int i=0; i<2048; i++) {
			if(g[i] != 0) {
				K++;
			} 
		}
		System.out.print(K);
		
		for(int i=2047; i>=0; i--) {
			if(g[i] != 0) {
				System.out.printf(" %d %.1f", i, g[i]);
			}
			
		}
		
		sc.close();

	}

}
