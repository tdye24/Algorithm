package PAT;

import java.util.*;
import java.io.*;
public class P1005 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		String str = sc.next();
		int sum = 0;
		String[] a = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
		int[] b = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		for(int i=0; i<str.length(); i++) {
			sum += b[Integer.parseInt(String.valueOf(str.charAt(i)))];
		}
		str = String.valueOf(sum);
		for(int i=0; i<str.length(); i++) {
			if(i == 0)
				System.out.print(a[Integer.parseInt(String.valueOf(str.charAt(i)))]);
			else 
				System.out.print(" " + a[Integer.parseInt(String.valueOf(str.charAt(i)))]);
		}
	}

}
