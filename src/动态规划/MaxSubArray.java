package ¶¯Ì¬¹æ»®;

import java.util.*;
import java.io.*;
public class MaxSubArray {

	static int MAX = 100024;
	static int N;
	static int[] a = new int[MAX];
	static int MaxSubSum() {
		int bj = 0;
		int bj_1 = 0;
		for(int i=0; i<N; i++) {
			if(bj_1>0) 
				bj_1 += a[i];
			else 
				bj_1 = a[i];
			if(bj_1 > bj) 
				bj = bj_1;
		}
		return bj;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		int sum = MaxSubSum();
		System.out.print(sum);
	}
}
