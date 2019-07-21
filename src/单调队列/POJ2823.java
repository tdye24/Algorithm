package 单调队列;

import java.util.*;
import java.io.*;

public class POJ2823 {
	static int[] a = new int[1000001];
	static int[] incqueue = new int[1000001];
	static int[] decqueue = new int[1000001];
	static int[] ans = new int[1000001];
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		
		int n = sc.nextInt();//数量
		int m = sc.nextInt();//窗口大小
		for(int i=1; i<=n; i++) {
			a[i] = sc.nextInt();
		}
		int head = 1, tail = 0;
		for(int i=1; i<=n; i++) {
			while(head <= tail && a[decqueue[tail]] > a[i]) 
				tail --;
			decqueue[++tail] = i;
			while(i - decqueue[head] >= m)
				head ++;
			if(i >= m) {
				ans[i-m+1] = a[decqueue[head]];
			}
				
		}
		for(int i=1; i<=n-m+1; i++) {
			if(i == 1) 
				System.out.print(ans[i]);
			else {
				System.out.print(" " + ans[i]);
			}
		}
		head = 1;
		tail = 0;
		for(int i=1; i<=n; i++) {
			while(head <= tail && a[incqueue[tail]] < a[i]) 
				tail --;
			incqueue[++tail] = i;
			while(i - incqueue[head] >= m)
				head ++;
			if(i >= m) {
				ans[i-m+1] = a[incqueue[head]];
			}
				
		}
		
		System.out.println("");
		for(int i=1; i<=n-m+1; i++) {
			if(i == 1) 
				System.out.print(ans[i]);
			else {
				System.out.print(" " + ans[i]);
			}
		}
		
	}

}
