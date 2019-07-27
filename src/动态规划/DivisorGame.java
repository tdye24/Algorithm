package ¶¯Ì¬¹æ»®;

import java.util.*;
import java.io.*;
public class DivisorGame {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		sc.close();
		if(n%2 == 0) 
			System.out.print("true");
		else 
			System.out.print("false");
		
	}

}
