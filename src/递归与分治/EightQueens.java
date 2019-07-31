package 递归与分治;

public class EightQueens {
	static int[] queen = new int[9];
	static int[][] table = new int[9][9];
	static int count = 0; //记录解数量
	static boolean available(int i, int j) {//放置在第i行第j列
		for(int k=1; k<i; k++) {
			if(j == queen[k])
				return false;
			if(Math.abs(i-k) == Math.abs(queen[k]-j)) {
				return false;
			}
		}
		return true;
	}
	
	static void put(int i) { //在第row行放置皇后
		for(int j=1;j<9;j++){ //从1-8行遍历这一行的八个空位
	        if(available(i, j)){ //放置在i行j列
	            queen[i] = j;
	            if(i == 8) { 
	                count++;
	                for(int t=1; t<9; t++) {
	                	System.out.print(queen[t] + " ");
	                }
	                System.out.println();
	                
	                return;
	            }
	            int nextrow = i + 1; //递归放下一个行
	            put(nextrow);
	        }
	    }
		return;
	}
	
	public static void main(String[] args) {
		put(1);
	    System.out.println(count);
	}

}
