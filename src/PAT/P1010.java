package PAT;

import java.io.*;
import java.util.*;
public class P1010 {
	static int getD(char c) {
		if(48 <= c && c <= 57)
			return c-48;
		else if(97 <= c && c <= 122)
			return c-87;
		else 
			return -1;
	}
	
	static long getDecimal(String s, long Radix) {
		long sum = 0;
		for(int i=s.length()-1; i>=0; i--) {
			sum += getD(s.charAt(i))*Math.pow(Radix, s.length()-i-1);
		}
		return sum;
	}
	
	static int getMinRadix(String s) {
		int minRadix = 2;
		for(int i=0; i<s.length(); i++)
			if(getD(s.charAt(i)) >= minRadix)
				minRadix = getD(s.charAt(i))+1;
		return minRadix;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		String s1 = sc.next();
		String s2 = sc.next();
		int tag = sc.nextInt();
		int radix = sc.nextInt();
		sc.close();
		long N1 = 0;
		long N2 = 0;
		if(tag == 1) {
			N1 = getDecimal(s1, radix);
			long minRadix = getMinRadix(s2);
			/**
			 * Note:N2 Radix上限不一定为N1
			 * eg:N1 = 6, N2 = 8, tag = 1, radix = 10, 即N2->radix?->N1
			 * minRadix = 9
			 * maxRadix = 6?是,但是maxRadix>=minRadix therefore maxRadix = N1>minRadix ? N1:minRadix;
			 */
			long maxRadix = N1>minRadix ? N1:minRadix;
		
			while (minRadix <= maxRadix) {
		        long midRadix = (minRadix + maxRadix) / 2;
		        long temp = getDecimal(s2, midRadix);
		        if (temp > N1) 
		        	maxRadix = midRadix - 1;
		        else if (temp == N1) {
		        	System.out.printf("%d\n", midRadix);
		        	return ;
		        }
		        else minRadix = midRadix + 1;
		    }
		} else {
			N2 = getDecimal(s2, radix);
			long minRadix = getMinRadix(s1);
			long maxRadix = N2>minRadix ? N2:minRadix;
			while (minRadix <= maxRadix) {
		        long midRadix = (minRadix + maxRadix) / 2;
		        long temp = getDecimal(s1, midRadix);
		        if (temp > N2) 
		        	maxRadix = midRadix - 1;
		        else if (temp == N2) {
		        	System.out.printf("%d\n", midRadix);
		        	return ;
		        }
		        else minRadix = midRadix + 1;
		    }
		}
		System.out.println("Impossible");
	}
}
