package PAT;

import java.util.*;
import java.io.*;
public class P1002 {
	public static double[] f = new double[1024];
	
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
			f[ex] += co;
		}
		
		int K = 0;
		for(int i=0; i<1024; i++) {
			if(f[i] != 0) {
				K++;
			} 
		}
		System.out.print(K);
		
		for(int i=1023; i>=0; i--) {
			if(f[i] != 0) {
				System.out.printf(" %d %.1f", i, f[i]);
			}
			
		}

	}

}
