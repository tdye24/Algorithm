package PAT;

import java.util.*;
import java.io.*;

public class P1007 {
	static int MAX = 100024;
	static int N;
	static int[] a = new int[MAX];
	static Queue<Integer> queue = new LinkedList<>();
	static int MaxSubSum(int left, int right) {
		int sum = 0;
		if(left == right) {
			sum = a[left] > 0 ? a[left]:0;
		} else {
			int center = (left+right)/2;
			int leftsum = MaxSubSum(left, center);
			int rightsum = MaxSubSum(center+1, right);
			int s1=0; //中间往左走，存储最大值
			int lefts = 0; //中间往左走，存储临时值
			for(int i=center; i>=left; i--) {
				lefts += a[i];
				if(lefts > s1) {
					s1 = lefts;
				}
					
			}
			int s2 = 0; //中间往右走，存储最大值
			int rights = 0; //中间往右走，存储临时值
			for(int i=center+1; i<=right; i++) {
				rights += a[i];
				if(rights > s2) {
					s2 = rights;
				}
					
			}
			sum = s1 + s2;
			
			if(sum < leftsum) {
				sum = leftsum;
			}
			if(sum < rightsum) {
				sum = rightsum;
			}
		}
		return sum;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		N = sc.nextInt();
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		int sum = MaxSubSum(0, N-1);
		System.out.print(sum);
	}

}
