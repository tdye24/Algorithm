package Ì°ÐÄ·¨;

public class ZRD extends Thread{
	public int weight = 50;
	
	public void run() {
//		for(int i=0; i<5; i++) {
//			System.out.println(Thread.currentThread().getName() + " " + i);
//		}
		
		
		try {
			System.out.println(this.weight + Thread.currentThread().getName());
			Thread.sleep(3000);
			this.weight -= 5;
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		System.out.println("Exit from thread" + Thread.currentThread().getName());
		
	}
	
	
	public static void main(String[] args) {
		ZRD zrd = new ZRD();
		Thread thread1 = new Thread(zrd, "T1");
		Thread thread2 = new Thread(zrd, "T2");
		thread1.start();
		thread2.start();
		System.out.println("Exit from Thread" + "--" +  Thread.currentThread().getName());
	}

}
