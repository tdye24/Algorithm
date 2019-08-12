package PAT;

import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class P1049 {

	public static void main(String[] args) {
		int ans = 0;
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		BigInteger N = new BigInteger(sc.next());
		sc.close();
		while(true) {
			String str = N.toString();
			for(int i=0; i<str.length(); i++)
				if(str.charAt(i) == '1')
					ans++;
			if(str.equals("1"))
				break;
			else
				N = N.subtract(new BigInteger("1"));
		}
		System.out.println(ans);
	}

}
