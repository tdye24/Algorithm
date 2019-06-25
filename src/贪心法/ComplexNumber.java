package 贪心法;

public class ComplexNumber
{
	public int real;
	public int image;

	public ComplexNumber(int a,int b)
	{
		real=a;
		image=b;
	}

	public void biaodashi()
	{
		System.out.println("="+real+"+"+image+"i");
	}

	public int RealPart()
	{
		System.out.println("a="+real);
		return real;
	}
	public int ImagePart()
	{
		System.out.println("b="+image);
		return image;
	}
	public void add(ComplexNumber c){
		int a,b;
		a=this.real+c.real;
		b=this.image+c.image;
		System.out.println("(a1+a2)+(b1+b2)i="+a+"+"+b+"i");
	}

	public void mul(ComplexNumber c){
		int a,b;
		a=this.real*c.real-this.image*c.image;
		b=this.image*c.real+this.real*c.image;
		System.out.println("(a1+a2)+(b1+b2)i="+a+"+"+b+"i");
	}
	public static void main(String[] args) 
	{
		ComplexNumber x=new ComplexNumber(3,4);
		ComplexNumber y=new ComplexNumber(1,2);
		//x.getvalue(1,2);
		//y.getvalue(3,4);
		System.out.print("表达式1");
		x.biaodashi();
		System.out.print("表达式2");
		y.biaodashi();
		System.out.println("表达式1的实部与虚部：");
		int a1=x.RealPart();
		int b1=x.ImagePart();
		System.out.println("表达式2的实部与虚部：");
		int a2=y.RealPart();
		int b2=y.ImagePart();
		System.out.println("表达式1与2相加之和为");
		x.add(y);
		System.out.println("表达式1与2相乘为");
	    x.mul(y);

	}
}
