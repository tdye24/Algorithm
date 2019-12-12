package LeetCode;

import java.util.*;
import java.io.*;
public class L128 {
	public static int longestConsecutive(int[] nums) {
		HashSet<Integer> set = new HashSet<Integer>();
		for(int i=0; i<nums.length; i++) {
			set.add(nums[i]);
		}
		int currentNum, currentLen, longest = 0;
		for(int i=0; i<nums.length; i++) {
			if(!set.contains(nums[i]-1)) {
				currentLen = 1;
				currentNum = nums[i];
				while(set.contains(currentNum+1)) {
					currentNum = currentNum + 1;
					currentLen = currentLen + 1;
				}
				if(currentLen > longest)
					longest = currentLen;
			}
		}
		return longest;
	}
	public static void main(String[] args) {
		int nums[] = new int[] {};
		int len = longestConsecutive(nums);
		System.out.println(len);

	}

}
