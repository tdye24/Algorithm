package PAT;

import java.util.*;
import java.io.BufferedInputStream;;
public class P1001 {
	public static final int MAX = 20;
	public static void solve(int a) {
		String flag;
		int start;
		if(a < 0) {
			flag = "-";
			start = 1;
		} else {
			flag = "";
			start = 0;
		}
		String temp = Integer.toString(a);
		char[] str = new char[MAX]; 
		for(int i=0; i<MAX; i++) {
			str[i] = '\0';
		}
		int count = 0;
		int j = MAX - 1;
		for(int i = temp.length()-1; i>=start; ) {
			if(count > 0 && count%3 == 0) {
				str[j--] = ',';
				count = 0;
			} else {
				str[j--] = temp.charAt(i);
				i--;
				count++;
			}
			
		}
		System.out.print(flag);
		for(int k=0; k<MAX; k++) {
			if(str[k] != '\0') {
				System.out.print(str[k]);
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int a = sc.nextInt();
		int b = sc.nextInt();
		solve(a+b);
		sc.close();
		
	}

}
