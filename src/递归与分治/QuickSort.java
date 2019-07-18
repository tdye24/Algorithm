package µÝ¹éÓë·ÖÖÎ;

import java.io.BufferedInputStream;
import java.util.Scanner;

public class QuickSort {
	public static void quickSort(int[] a, int left, int right) {
		int base = a[left];
		int i =  left;
		int j = right;
		if(left > right) 
			return ;
		while(i < j) {
			while(a[j]>=base&&i<j) {
				j--;
			}
			while(a[i]<=base&&i<j) {
				i++;
			}
			if(i<j) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		a[left] = a[i];
		a[i] = base;
		quickSort(a, left, i-1);
		quickSort(a, i+1, right);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int[] a = new int[24];
		for(int i=0; i<N; i++) {
			a[i] = sc.nextInt();
		}
		quickSort(a, 0, N-1);
		for(int i=0; i<N; i++) {
			System.out.print(a[i] + " ");
		}

	}

}
