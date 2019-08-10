package PAT;

import java.math.BigInteger;
import java.util.*;
import java.io.*;

public class P1024 {

	static boolean isPalin(BigInteger n) {
		int[] temp = new int[1010];
		int num = 0;
		while(n.compareTo(new BigInteger("0")) > 0) {
			temp[num++] += n.divideAndRemainder(new BigInteger("10"))[1].intValue();
			n = n.divide(new BigInteger("10"));
		}
		for(int i=0; i<=num/2; i++) {
			if(temp[i] != temp[num-1-i])
				return false;
		}
		return true;
	} 

	static BigInteger reverse(BigInteger n) {
		int[] temp = new int[1010];
		int num = 0;
		while(n.compareTo(new BigInteger("0")) > 0) {
			BigInteger x = n.divideAndRemainder(new BigInteger("10"))[1];
			temp[num++] += x.intValue();
			n = n.divide(new BigInteger("10"));
		}
		BigInteger sum = new BigInteger("0");
		BigInteger e = BigInteger.valueOf(10);
		BigInteger BigResult = BigInteger.valueOf(0);
		for(int i=0; i<num; i++) {
			BigInteger k = BigInteger.valueOf(temp[i]);
			BigResult = e.pow(num-1-i).multiply(k);
			sum = sum.add(BigResult);
		}
		return sum;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		BigInteger N = new BigInteger(sc.next());
	    int K = sc.nextInt();
		sc.close();
		int i = 0;
		while(!isPalin(N)) {
			N = N.add(reverse(N));
			i++;
			if(i >= K)
				break;
		}
		System.out.println(N);
		System.out.println(i);
	}
}
