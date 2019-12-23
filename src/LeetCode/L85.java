package LeetCode;

import java.util.Stack;

public class L85 {
	public static int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.length; ++i) {
            while (stack.peek() != -1 && heights[stack.peek()] >= heights[i])
                maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack.peek() - 1));
            stack.push(i);
        }
        while (stack.peek() != -1)
            maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - 1 - stack.peek()));
        return maxarea;
    }
	
	public static int maximalRectangle(char[][] matrix) {
		int maximalRectangle = 0;
		if(matrix.length == 0 || matrix[0].length == 0)
			return 0;
		int[] heights = new int[matrix[0].length];
		for(int i=0; i<matrix.length; i++) {
			for(int j=0; j<matrix[0].length; j++) {
				if(matrix[i][j] == '1')
					heights[j] += 1;
				else
					heights[j] = 0;
			}
			maximalRectangle = Math.max(maximalRectangle, largestRectangleArea(heights));
		}
		return maximalRectangle;
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char[][] matrix = new char[][] {	{'1','0','1','0','0'}, 
											{'1','0','1','1','1'}, 
											{'1','1','1','1','1'}, 
											{'1','0','0','1','0'}
										};
		System.out.println(maximalRectangle(matrix));
	}

}
