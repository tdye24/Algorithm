package PAT;

import java.util.*;
import java.io.*;

class I {
	String name;
	String password;
	public I(String name, String password) {
		this.name = name;
		this.password = password;
	}
}

public class P1035 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		ArrayList<I> arr = new ArrayList<>();
		String name, password;
		int n = sc.nextInt();
		for(int i=0; i<n; i++) {
			boolean flag = false;
			name = sc.next();
			password = sc.next();
			
			for(int j=0; j<password.length(); j++) {
				if(password.charAt(j) == '1' || password.charAt(j) == '0' || password.charAt(j) == 'l' || password.charAt(j) == 'O') {
					flag = true;
					break;
				}
					
			}
			String str1 = password.replace('1', '@');
			String str2 = str1.replace('0', '%');
			String str3 = str2.replace('l', 'L');
			String str4 = str3.replace('O', 'o');
			if(flag)
				arr.add(new I(name, str4));
		}
		sc.close();
		
		if(arr.size() >= 1) {
			System.out.println(arr.size());
			for(int i=0; i<arr.size(); i++) {
				System.out.println(arr.get(i).name + " " + arr.get(i).password);
			}
		} else if(n == 1) 
			System.out.println("There is 1 account and no account is modified");
		else 
			System.out.println("There are " + n + " accounts and no account is modified");

	}

}
