package 回溯法;

import java.io.IOException;
import java.util.Scanner;

public class PrimeCircle {
	public int n;
	public int sum;//解决方案数
	public int[] arr = new int[50];
	
	public PrimeCircle(int n) {
		this.n= n;
		for(int i=1; i<=n; i++) {
			this.arr[i] = i;
		}
	}
	
	public boolean isPrime(int sum) {
		int k = (int) Math.sqrt(sum) + 1;
		for(int i=2; i<k; i++) {
			if(sum % i == 0) {
				return false;
			}
		}
		return true;
	}
	
	public void backTrack(int t) {
		int temp;
		if(t > this.n) {
			if(isPrime(arr[n] + arr[1])) {
				this.sum ++;
				for(int j=1; j<=n; j++) {
					System.out.print(this.arr[j] + " ");
				}
				System.out.println("");
			}
		} else {
			for(int i=t; i<=n; i++) {
				temp = arr[i];
				arr[i] = arr[t];
				arr[t] = temp;
				if(isPrime(arr[t-1] + arr[t])) {
					backTrack(t+1);
				}
				temp = arr[i];
				arr[i] = arr[t];
				arr[t] = temp;
			}
		}
		
	}
	
	public void solve() {
		for(int i=1; i<=this.n; i++) {
			arr[i] = i;
		}
		backTrack(2);
		System.out.println("方案总数为:" + this.sum);
	}
	
	public static void main(String[] args) throws IOException {
		@SuppressWarnings("resource")
		Scanner in = new Scanner(System.in);
		System.out.println("请输入n:");
		PrimeCircle primeCircle = new PrimeCircle(in.nextInt());
		primeCircle.solve();

	}

}
