package PAT;

import java.util.*;
import java.io.*;
public class P1019 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		Deque<Integer> queue = new LinkedList<Integer>();
		Deque<Integer> tempqueue = new LinkedList<Integer>();
		int n = sc.nextInt();
		int base = sc.nextInt();
		do {
			queue.offer(n % base);
			n = n/base;			
		} while(n != 0);
		tempqueue.addAll(queue);
		boolean flag = true;
		while(queue.size() > 1) {
			if(queue.pollFirst() != queue.pollLast()) {
				flag = false;
				break;
			}
		}
		System.out.println(flag ? "YES":"NO");
		while(!tempqueue.isEmpty()) {
			if(tempqueue.size() == 1) {
				System.out.print(tempqueue.pollLast());
			} else if(tempqueue.size() > 1) {
				System.out.print(tempqueue.pollLast() + " ");
			}
		}
	}
}
