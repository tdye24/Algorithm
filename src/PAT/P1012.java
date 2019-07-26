package PAT;

import java.util.*;
import java.io.*;

class Stu {
	String ID;
	int C;
	int M;
	int E;
	int A;
	int Arank;
	public Stu(String ID, int C, int M, int E) {
		this.ID = ID;
		this.C = C;
		this.M = M;
		this.E = E;
		this.A = (C+M+E)/3;
	}
}

public class P1012 {
	static void getRank(ArrayList<Stu> list, String ID) {
		int Crank = 1;
		int Mrank = 1;
		int Erank = 1;
		int Arank = 1;
		Stu currentStu = null;
		for(int i=0; i<list.size(); i++) {
			if(ID.equals(list.get(i).ID)) {
				currentStu = list.get(i);
				break;
			}
		}
		if(currentStu == null) {
			System.out.println("N/A");
			return ;
		}
			
		for(int i=0; i<list.size(); i++) {
			if(list.get(i).C > currentStu.C) 
				Crank ++;
		}
		for(int i=0; i<list.size(); i++) {
			if(list.get(i).M > currentStu.M) 
				Mrank ++;
		}
		for(int i=0; i<list.size(); i++) {
			if(list.get(i).E > currentStu.E) 
				Erank ++;
		}
		for(int i=0; i<list.size(); i++) {
			if(list.get(i).A > currentStu.A) 
				Arank ++;
		}
		
		int best = Math.min(Crank, Math.min(Mrank, Math.min(Erank, Arank)));
		if(Arank == best) {
			System.out.println(best + " " + "A");
			return ;
		}
		if(Crank == best) {
			System.out.println(best + " " + "C");
			return ;
		}
		if(Mrank == best) {
			System.out.println(best + " " + "M");
			return ;
		}
		if(Erank == best) {
			System.out.println(best + " " + "E");
			return ;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		ArrayList<Stu> list = new ArrayList<>();
		int N = sc.nextInt();
		int M = sc.nextInt();
		for(int i=0; i<N; i++) {
			list.add(new Stu(sc.next(), sc.nextInt(), sc.nextInt(), sc.nextInt()));
		}
		
		for(int i=0; i<M; i++) {
			getRank(list, sc.next());
		}
		
		sc.close();

	}

}
