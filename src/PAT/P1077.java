package PAT;

import java.util.*;
import java.io.*;
public class P1077 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		String n = sc.nextLine(); //³Ôµô»Ø³µ
		String suffix = sc.nextLine();
		for(int i=0; i<N-1; i++) {
			String str = sc.nextLine();
			for(int j=suffix.length()-1, k=str.length()-1; j>=0&&k>=0; j--, k--) {
				if(str.charAt(k) != suffix.charAt(j)) {
					suffix = suffix.substring(j+1);
					break;
				}
			}
		}
		sc.close();
		if(suffix.length() != 0) 
			System.out.println(suffix);
		else
			System.out.println("nai");
	}
	

}
