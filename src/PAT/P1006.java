package PAT;

import java.util.*;
import java.io.*;
public class P1006 {
	static final int MAX = 1024;
	static int strcmp(String s1, String s2) {
		return s1.compareTo(s2);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		String[] ID = new String[MAX];
		String[] In = new String[MAX];
		String[] Out = new String[MAX];
		for(int i=0; i<n; i++) {
			ID[i] = sc.next();
			In[i] = sc.next();
			Out[i] = sc.next();
		}
		int early = 0;
		for(int i=1; i<n; i++) {
			if(strcmp(In[early],In[i]) > 0) {
				early = i;
			}
		}
		int late = 0;
		for(int i=1; i<n; i++) {
			if(strcmp(Out[i],Out[late]) > 0) {
				late = i;
			}
		}
		
		System.out.println(ID[early] + " " + ID[late]);
		
		
	}

}
