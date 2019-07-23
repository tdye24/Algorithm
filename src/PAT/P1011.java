package PAT;

import java.util.*;
import java.io.*;
public class PAT1011 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		float temp ;
		Character[] ch = new Character[] {'W', 'T', 'L'};
		Character[] cc = new Character[3];
		float[] value = new float[3];
		for(int i=0; i<3; i++) {
			float max = -Float.MAX_VALUE;
			for(int j=0; j<3; j++) {
				temp = sc.nextFloat();
				if(temp > max) {
					max = temp;
					cc[i] = ch[j];	
				}
				
			}
			value[i] = max;
		}
		
		float res = (float) ( (value[0]*value[1]*value[2]*0.65-1)*2);
		System.out.printf("%c %c %c %.2f\n", cc[0], cc[1], cc[2], res);
	}

}
