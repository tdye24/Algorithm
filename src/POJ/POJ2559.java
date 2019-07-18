package POJ;

import java.util.*;
import java.io.*;

class Item {
	int height;
	int width;
	
	public Item(int height, int width) {
		this.height = height;
		this.width = width;
	}
}
public class POJ2559 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		Stack<Item> stack = new Stack<>();
		while(true) {
			int temp = 0;
			int max = 0;
			int n = sc.nextInt();
			if(n == 0) {
				break ;
			}
			for(int i=0; i<n; i++) {
				Item item = new Item(sc.nextInt(), 1);
				if(stack.isEmpty() || item.height > stack.peek().height) {
					stack.push(item);
				} else {
					Item deItem = null;
					while(item.height <= stack.peek().height) {
						deItem = stack.pop();
						temp = deItem.height*deItem.width;
						if(max < temp) {
							max = temp;
						}
						if(stack.isEmpty() || item.height > stack.peek().height) 
							break ;
						stack.peek().width += deItem.width;
					}
					item.width += deItem.width;
					stack.push(item);
				}
			}
			while(!stack.isEmpty()) {
				temp = stack.peek().height*stack.pop().width;
				if(max < temp) {
					max = temp;
				}
			}
			System.out.println(max);
		}	
	}
}
