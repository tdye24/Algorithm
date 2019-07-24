package PAT;

import java.util.*;
import java.io.*;

public class P1007DPOn {
	static int MAX = 100024;
	static int N;
	static int[] a = new int[MAX];
	static int besti, bestj;
	static int tempi = 0, maxsum = -1;
	static void MaxSubSum() {
		int sum = 0;
		for(int i=0; i<N; i++) {
			sum += a[i];
			if(sum > maxsum) {
				tempi = besti;
				bestj = i;
				maxsum = sum;
			} else if(sum < 0) {
				besti = i+1;
				sum=0;
			}
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		N = sc.nextInt();
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		MaxSubSum();
		if(maxsum==-1)
			System.out.println("0" + " " + a[0] + " " + a[N-1]);
		else 
			System.out.println(maxsum + " " + a[tempi] + " " + a[bestj]);
		
		sc.close();
	}

}
