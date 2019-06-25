package hunan;

import java.util.Scanner;

public class Main_ {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] arr = new int[n];
		for(int j=0; j<n; j++) {
			int sum = 0;
			String str = Integer.toBinaryString(scanner.nextInt());
			for(int i=0; i<str.length(); i++) {
				if(str.charAt(i) == '1') {
					sum ++;
				}
			}
			arr[j] = sum;
		}
		for(int i=0; i<n; i++) {
			System.out.println(arr[i]);
		}
	}
}
