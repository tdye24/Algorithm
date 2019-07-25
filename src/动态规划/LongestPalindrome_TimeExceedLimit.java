package 动态规划;

import java.util.*;
import java.io.*;
public class LongestPalindrome_TimeExceedLimit {
	static final int MAX = 50;
	static ArrayList<String>[][] table = new ArrayList[MAX][MAX];
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		String in = sc.next();
		int n = in.length();
		sc.close();	
		if(n == 0) 
			return;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				table[i][j] = new ArrayList<String>();
			}
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j+i<n; j++) {
				if(in.charAt(j) == in.charAt(j+i)) {
					if(i == 0) {
						table[j][j+i].add(String.valueOf(in.charAt(j)));
					} else if(i == 1) {
						table[j][j+i].add(String.valueOf(in.subSequence(j, j+i+1)));
					} else if(table[j+1][j+i-1].size() == 1){
						table[j][j+i].add(in.substring(j, j+i+1));
					} else {
						table[j][j+i].addAll(table[j+1][j+i]);
						for(int k=0; k<table[j+1][j+i].size(); k++) {
							for(int l=0; l<table[j][j+i-1].size(); l++) {
								if(!table[j][j+i].get(k).equals(table[j][j+i-1].get(l))) {
									table[j][j+i].add(table[j][j+i-1].get(l));
								}
							}
							
						}
					}
				} else {
					table[j][j+i].addAll(table[j+1][j+i]);
					
					for(int k=0; k<table[j][j+i-1].size(); k++) {
						if(!table[j][j+i].contains(table[j][j+i-1].get(k))) {
							table[j][j+i].add(table[j][j+i-1].get(k));
						}
					}
						
					
				}
			}
		}
		int length = 0;
		String longestPalindrome = "";
		for(int i=0; i<table[0][n-1].size(); i++) {
			String str = table[0][n-1].get(i);
			if(table[0][n-1].get(i).length() > length) {
				length = table[0][n-1].get(i).length();
				longestPalindrome = table[0][n-1].get(i);
			}
		}
		System.out.print(longestPalindrome);//可能有多个结果，仅选择了第一个
	}
}
