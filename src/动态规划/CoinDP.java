package ¶¯Ì¬¹æ»®;

import java.util.Scanner;
import java.io.BufferedInputStream;;
public class CoinDP {
	public static final int[] V =  {1, 5, 10, 25};
	
	public static int rec(int sum, int[] N) {
		for(int i=0; i<3; i++) {
			if(sum == V[i] && N[i] != 0) {
				return 1;
			}
		}
		int[] N1 = {N[0]-1, N[1], N[2], N[3]};
		int sum1 = sum-1;
		int[] N5 = {N[0], N[1]-1, N[2], N[3]};
		int sum5 = sum-5;
		int[] N10 = {N[0], N[1], N[2]-1, N[3]};
		int sum10 = sum-10;
		int[] N25 = {N[0]-1, N[1], N[2], N[3]-1};
		int sum25 = sum-25;
		
		int x = Math.min(rec(sum1, N1)+1, rec(sum5, N5)+1);
		int y = Math.min(rec(sum10, N10)+1, rec(sum25, N25)+1);
		return Math.min(x, y);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int sum = sc.nextInt();
		int N[] = new int[4];
		for(int i=0; i<4; i++) {
			N[i] = sc.nextInt();
		}
		int ans = rec(sum, N);
		System.out.println(ans);

	}

}
