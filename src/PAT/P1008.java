package PAT;

import java.util.*;
import java.io.*;
public class P1008 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int N = sc.nextInt();
		int previous = 0;
		int current = 0;
		int height = 0;
		int sum = 0;
		for(int i=0; i<N; i++) {
			current = sc.nextInt();
			height = current - previous;
			if(height >= 0) {
				sum += 6*height;
			} else {
				sum -= 4*height;
			}
			previous = current;;
		}
		sum += 5*N;
		System.out.println(sum);
	}

}
