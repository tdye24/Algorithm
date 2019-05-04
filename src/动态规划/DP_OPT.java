package ¶¯Ì¬¹æ»®;

public class DP_OPT {
	public static int rec_opt(int[] arr, int i) {
		if(i==0) {
			return arr[0];
		} else if(i==1) {
			return arr[0]>arr[1] ? arr[0]:arr[1];
		} else {
			return rec_opt(arr, i-2) + arr[i] > rec_opt(arr, i-1) ? rec_opt(arr, i-2) + arr[i]:rec_opt(arr, i-1);
		}
	}
	
	public static int dp_opt(int[] arr, int i) {
		int[] OPT = new int[arr.length];
		OPT[0] = arr[0];
		OPT[1] = arr[0]>arr[1] ? arr[0]:arr[1];
		for(int j=2; j<arr.length; j++) {
			OPT[j] = OPT[j-2] + arr[j] > OPT[j-1] ? OPT[j-2] + arr[j]:OPT[j-1];
		}
		return OPT[i];
	}
	
	public static void main(String[] args) {
		int[] arr = {1, 2, 4, 1, 7, 8, 3};
		System.out.println(rec_opt(arr, 6));
		System.out.println(dp_opt(arr, 6));
	}

}
