package PAT;

import java.util.*;
import java.io.*;

class Student {
	public String name;
	public String sex;
	public String ID;
	public int grade;
	
	public Student(String name, String sex, String ID, int grade) {
		this.name = name;
		this.sex = sex;
		this.ID = ID;
		this.grade = grade;
	}
}

public class P1036 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt();
		Student lowmale = new Student("", "", "", 101);
		Student highfemale = new Student("", "", "", -1);
		for(int i=0; i<n; i++) {
			String name = sc.next();
			String sex = sc.next();
			String ID = sc.next();
			int grade = sc.nextInt();
			if(sex.equals("M")) {
				if(grade < lowmale.grade)
					lowmale = new Student(name, sex, ID, grade);
			} else {
				if(grade > highfemale.grade) 
					highfemale = new Student(name, sex, ID, grade);
			}	
		}
		
		System.out.println(highfemale.grade == -1? "Absent":highfemale.name + " " + highfemale.ID);
		System.out.println(lowmale.grade == 101? "Absent":lowmale.name + " " + lowmale.ID);
		if(lowmale.grade == 101||highfemale.grade == -1) 
			System.out.println("NA");
		else 
			System.out.println(highfemale.grade - lowmale.grade);
			
		sc.close();
		
	}

}
