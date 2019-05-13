package 贪心法;

public class EgyptianQuestion {
	
	public int a;//分子
	public int b;//分母
	
	public EgyptianQuestion(int a, int b) {
		this.a = a;
		this.b = b;
	}
	
	public int gcm(int a, int b) {
		if(a > b) {
			int t = a;
			a = b;
			b = t;
		}
		
		if(b%a == 0) {
			return a;
		} else {
			while(b%a != 0) {
				int t = b;
				b = a;	
				a = t % a;
				
			}
			return a;
		}
	}
	
	public int rec(int a, int b) {
		if(a == 1) {
			System.out.print("1/" + b);
			return b;
		}
		int c = b/a + 1;
		int tempa = a*c-b;
		int tempb = b*c;
		int gcm = gcm(tempa, tempb);
		System.out.print("1/" + c + " + ");
		rec(tempa/gcm, tempb/gcm);
		return 0;
	}
	
	public void solve() {
		rec(this.a, this.b);
	}
		
	public static void main(String[] args) {
		EgyptianQuestion question = new EgyptianQuestion(3, 88);
		question.solve();
	}

}
