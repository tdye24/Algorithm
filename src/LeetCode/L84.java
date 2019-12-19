package LeetCode;
import java.util.*;
public class L84 {
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
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] heights = new int[] {2,1,5,6,2,3};
		System.out.println(largestRectangleArea(heights));
	}

}
