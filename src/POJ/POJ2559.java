package POJ;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

class Item {
	BigInteger height;
	BigInteger width;
	
	public Item(BigInteger height, BigInteger width) {
		this.height = height;
		this.width = width;
	}
}
public class POJ2559 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		Stack<Item> stack = new Stack<>();
		while(true) {
			BigInteger temp = new BigInteger("0");
			BigInteger max = new BigInteger("0");
			int n = sc.nextInt();
			if(n == 0) {
				break ;
			}
			for(int i=0; i<n; i++) {
				Item item = new Item(sc.nextBigInteger(), new BigInteger("1"));
				if(stack.isEmpty() || item.height.compareTo(stack.peek().height) > 0) {
					stack.push(item);
				} else {
					Item deItem = null;
					while(item.height.compareTo(stack.peek().height) <= 0) {
						deItem = stack.pop();
						temp = deItem.height.multiply(deItem.width);
						if(max.compareTo(temp) < 0) {
							max = temp;
						}
						if(stack.isEmpty() || item.height.compareTo(stack.peek().height) > 0) 
							break ;
						stack.peek().width = stack.peek().width.add(deItem.width);
					}
					item.width = item.width.add(deItem.width);
					stack.push(item);
				}
			}
			while(!stack.isEmpty()) {
				temp = stack.peek().height.multiply(stack.pop().width);
				if(max.compareTo(temp) < 0) {
					max = temp;
				}
			}
			System.out.println(max);
		}	
	}
}
