package LeetCode;
import java.util.*;

public class L1 {
	public static int[] twoSum(int[] nums, int target) {
		HashMap<Integer, Integer> mp = new HashMap<>();
		for(int i=0; i<nums.length; i++) {
			if(mp.containsKey(target-nums[i]))
				return new int[] {Math.min(i, mp.get(target-nums[i])), Math.max(i, mp.get(target-nums[i])),};
			else
				mp.put(nums[i], i);
		}
		return new int[] {};   
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] nums = new int[] {2, 7, 11, 15};
		System.out.println(twoSum(nums, 9)[0] + " " + twoSum(nums, 9)[1]);

	}

}
