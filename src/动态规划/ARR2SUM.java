package 动态规划;

public class ARR2SUM {
	public static boolean rec_opt(int arr[], int i, int S) {
		if(S == 0) {
			return true;
		} else if(i == 0) {
			return arr[0] == S;
		} else if(arr[i] > S) {
			return rec_opt(arr, i-1, S);
		} else {
			boolean A = rec_opt(arr, i-1, S-arr[i]);
			boolean B = rec_opt(arr, i-1, S);
			return A||B;
		}
	}
	
	public static boolean dp_opt(int arr[], int S) {
		boolean[][] subset = new boolean[arr.length][S+1];
		for(int i=0; i<arr.length; i++) {
			subset[i][0] = true;
		}
		for(int i=1; i<S+1; i++) {
			subset[0][i] = false;
		}
		
		if(arr[0] <= S) {
			subset[0][arr[0]] = true;
		} 
		
		for(int i=1; i<arr.length; i++) {
			for(int s=1; s<S+1; s++) {
				if(arr[i] > s) {
					subset[i][s] = subset[i-1][s];
				} else {
					subset[i][s] = subset[i-1][s]||subset[i-1][s-arr[i]];
				}
			}
		}
		return subset[arr.length-1][S];
	}
	
	public static void main(String[] args) {
		int[] arr = {3, 34, 4, 12, 5, 2};
		System.out.println("==================");
		System.out.println("递归");
		System.out.println("==================");
		System.out.println(rec_opt(arr, 5, 9));
		System.out.println(rec_opt(arr, 5, 10));
		System.out.println(rec_opt(arr, 5, 11));
		System.out.println(rec_opt(arr, 5, 12));
		System.out.println(rec_opt(arr, 5, 13));
		System.out.println("==================");
		System.out.println("动态规划");
		System.out.println("==================");
		System.out.println(dp_opt(arr, 9));
		System.out.println(dp_opt(arr, 10));
		System.out.println(dp_opt(arr, 11));
		System.out.println(dp_opt(arr, 12));
		System.out.println(dp_opt(arr, 13));

	}

}
