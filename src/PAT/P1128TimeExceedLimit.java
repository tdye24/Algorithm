package PAT;

import java.util.*;
import java.io.*;
public class P1128TimeExceedLimit {
	static int[] arr = new int[1010];
	
	static boolean isValid(int[] arr,int N) {
		for(int i=2; i<=N; i++) {
			for(int j=1; j<i; j++) {
				if(arr[i] == arr[j])
					return false;
				if(Math.abs(i-j) == Math.abs(arr[i] - arr[j]))
					return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int K = sc.nextInt();
		for(int i=0; i<K; i++) {
			int N = sc.nextInt();
			for(int j=1; j<=N; j++) {
				arr[j] = sc.nextInt();
			}
			if(isValid(arr, N))
					System.out.println("YES");
			else
				System.out.println("NO");
		}
		sc.close();
	}

}
