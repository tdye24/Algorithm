package 贪心法;

interface Fx{
	void add(ComplexNumber2_2 c);
	void sub(ComplexNumber2_2 c);
	void mul(ComplexNumber2_2 c);
	void biaodashi();
	int RealPart();
	int ImagePart();
}

public class ComplexNumber2_2 implements Fx {
	private int real;
	private int image;

	public ComplexNumber2_2(int a,int b) {
		real=a;
		image=b;
	}
	
	public void biaodashi() {
		System.out.println("="+this.real+"+"+this.image+"i");
	}

	public int RealPart() {
		System.out.println("a="+this.real);
		return real;
	}
	
	public int ImagePart() {
		System.out.println("b="+this.image);
		return image;
	}
	
	public void add(ComplexNumber2_2 c) {
		int a,b;
		a=this.real+c.real;
		b=this.image+c.image;
		System.out.println("(a1+a2)+(b1+b2)i="+a+"+"+b+"i");
	}

	public void sub(ComplexNumber2_2 c) {
		int a,b;
		a=this.real-c.real;
		b=this.image-c.image;
		System.out.println("(a1-a2)+(b1-b2)i="+a+"+"+b+"i");
		
	}
	
	public void mul(ComplexNumber2_2 c) {
		int a,b;
		a=this.real*c.real-this.image*c.image;
		b=this.image*c.real+this.real*c.image;
		System.out.println("(a1+a2)+(b1+b2)i="+a+"+"+b+"i");
	}
	
	public static void main(String[] args) {
		ComplexNumber2_2 x=new ComplexNumber2_2(3,4);
		ComplexNumber2_2 y=new ComplexNumber2_2(1,2);
		System.out.print("表达式1");
		x.biaodashi();
		System.out.println("表达式1的实部与虚部：");
		int a1=x.RealPart();
		int b1=x.ImagePart();
		System.out.print("表达式2");
		y.biaodashi();
		System.out.println("表达式2的实部与虚部：");
		int a2=y.RealPart(); 
		int b2=y.ImagePart();
		
		System.out.println("表达式1与2相加之和为");
		x.add(y);
		System.out.println("表达式1与2相乘为");
	    x.mul(y);

	}

	
}
