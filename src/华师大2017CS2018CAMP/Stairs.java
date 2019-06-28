package »ªÊ¦´ó2017CS2018CAMP;

import java.io.BufferedInputStream;
import java.util.Scanner;
public class Stairs {
	public static int MAX = 200;
	public static int n;
	public static int solve(int[] a, int current, int jump) {
		if(a[current + jump] == n) {
			return 1;
		} else if(a[current + jump] == -1||a[current + jump] > n) {
			return 0;
		} else {
			return solve(a, current+jump, 1) + solve(a, current+jump, 2) + solve(a, current+jump, 3);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		n = sc.nextInt();
		int k = sc.nextInt();
		int a[] = new int[MAX];
		for(int i=1; i<MAX; i++) {
			a[i] = i;
		}
		int[] b = new int[MAX];
		for(int i=0; i<k; i++) {
			a[sc.nextInt()] = -1;
		}
		int sum = 0;
		sum += solve(a, 0, 1) + solve(a, 0, 2) + solve(a, 0, 3);
		System.out.println(sum);
		
		
	}

}
