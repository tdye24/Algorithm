package 递归与分治;

public class Perm <AnyType>{
	
	public AnyType[] arr;
	public int sum;
	
	public Perm(AnyType[] arr) {
		this.arr = arr;
	}
	
	public void Swap(AnyType[] arr, int i, int j) {
		AnyType temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	public void perm(AnyType[] arr, int p, int q) {
		if(p == q) {
			sum ++;
			for(int i=0; i<arr.length; i++) {
				System.out.print(arr[i] +" ");
			}
			System.out.println("");
		} else {
			for(int i=p; i<=q; i++) {
				Swap(arr, p, i);
				perm(arr, p+1, q);
				Swap(arr, p, i);
			}
		}
	}
	
	public void solve() {
		this.perm(arr, 0, arr.length-1);
		System.out.println("共有" + sum +"种排列方式:");
	}
	
	public static void main(String[] args) {
		Integer[] arr = {1, 2, 3};
		Character[] list = {'a', 'b', 'c', 'd'};
		
		Perm<Integer> perm = new Perm<Integer>(arr);
		perm.solve();
		Perm<Character> perm2 = new Perm<Character>(list);
		perm2.solve();

	}

}
