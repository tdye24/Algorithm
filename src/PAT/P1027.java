package PAT;

import java.util.*;
import java.io.*;
public class P1027 {
	public static Character[] table = new Character[] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
	public static String solve(int num) {
		String str = "";
		str += table[num/13];
		str += table[num%13];
		return str;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();
		int num3 = sc.nextInt();
		System.out.println("#" + solve(num1) + solve(num2) + solve(num3));
		
		sc.close();
	}

}
