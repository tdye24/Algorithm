package PAT;

import java.util.*;
import java.io.*;
public class P1037 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		long[] CP = new long[100005];
		long[] CN = new long[100005];
		int NC = sc.nextInt();
		long C = 0;
		int m = 0, n = 0;
		for(int i=0; i<NC; i++) {
			C = sc.nextLong();
			if(C > 0) 
				CP[m++] = C;
			else 
				CN[n++] = C;
		}
		long[] PP = new long[100005];
		long[] PN = new long[100005];
		int NP = sc.nextInt();
		long P = 0;
		int p = 0, q = 0;
		for(int i=0; i<NP; i++) {
			P = sc.nextLong();
			if(P > 0)
				PP[p++] = P;
			else
				PN[q++] = P;
		}
		
		Arrays.sort(CP, 0, m);
		Arrays.sort(PP, 0, p);
		
		Arrays.sort(CN, 0, n);
		Arrays.sort(PN, 0, q);
		
		long sum = 0;
		for(int i=m-1, j=p-1; i>=0 && j>=0; i--, j--)
			sum += CP[i]*PP[j];
		for(int i=0, j=0; i<n && j<q; i++, j++)
			sum += CN[i]*PN[j];
		System.out.println(sum);	
	}

}