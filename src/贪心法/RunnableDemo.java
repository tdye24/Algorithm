package 贪心法;
 
class RenWu implements Runnable{
	//重写run()方法
	public void run()
	{
		//获取当前线程的名字
		System.out.println("当前线程："+Thread.currentThread().getName());
		for(int i=0;i<30;i++)
		{
			System.out.print("A");
			
		}
	}
}
public  class RunnableDemo{
	public static  void main(String[] args){
		//创建一个任务对象
		RenWu rw=new RenWu();
		//将实现的Runnable类的实例传入构造函数
		Thread thread=new Thread(rw);
		thread.start();
		//获取主线程的名字
		System.out.println("主线程：["+Thread.currentThread().getName()+"]");
		for(int i=0;i<30;i++)
		{
			System.out.print("C");
		}
	}
}