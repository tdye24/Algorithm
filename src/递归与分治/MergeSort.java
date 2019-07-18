package µ›πÈ”Î∑÷÷Œ;

import java.util.*;
import java.io.*;
public class MergeSort {
	public static int[]	a = new int[50];
	public static int[] sort(int[] a, int left, int right) {
		int mid = (left+right)/2;
		if(left < right) {
			sort(a, left, mid);
			sort(a, mid+1, right);
			merge(a, left, mid, right);
		}
		return a;
	}
	
	public static void merge(int[] a, int left, int mid, int right) {
		int[] temp = new int[right-left+1];
		int i = left;
		int j = mid+1;
		int k = 0;
		while(i<=mid && j<=right) {
			if(a[i] <= a[j]) {
				temp[k++] = a[i++];
			} else {
				temp[k++] = a[j++];
			}
		}
		while(i<=mid) {
			temp[k++] = a[i++];
		}
		while(j<=right) {
			temp[k++] = a[j++];
		}
		for(i=left, k=0; i<=right;) {
			a[i++] = temp[k++];
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		sort(a, 0, N-1);
		for(int i=0; i<N; i++) {
			System.out.print(a[i] + " ");
		}

	}

}
