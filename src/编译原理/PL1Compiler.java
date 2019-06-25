package 编译原理;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class PL1Compiler {
	static int no = 0;
	static int tempIndex = 0;
	static String IDENTIFIER = "IDENTIFIER";
	static String INTEGER = "INTEGER";
	static String DECIMALS = "DECIMALS";
	static String ERROR = "ERROR";
	static String STRING = "STRING";
	static String space = "";
	File file;
	
	String[] reserve = {"new","if","else","while","throw","this","int","String",
							"char","double","float","static","public","private",
								"default","switch","catch","void","try","return", "class"};

	String[] operator = {"=","+","-","*","/","++","--","==","!=",">","<",">=",
			"<=","&&","||","!","."};

	char[] divide = {'<','>','(',')','{','}','[',']','"',',',';'};
	
	public PL1Compiler(File file) {
		this.file = file;
	}
	
	public String file2String(File file) throws IOException {
		StringBuilder output = new StringBuilder();
		try {
			BufferedReader bufferedReader = new BufferedReader(new FileReader(file));
			String str = "";
			while((str = bufferedReader.readLine()) != null){
				output.append(System.lineSeparator() + str);//考虑到跨平台用System.lineSeparator()而不用'\n'
			}
			bufferedReader.close();
		} catch (FileNotFoundException e) {e.printStackTrace();}
		
		return output.toString();
	}

	public char[] preTreatment(char[] sourceFile) {
		char []output = new char[10000];
		int index = 0;
		if(sourceFile.length !=0 ) {
			for(int i=0; i<sourceFile.length; i++) {
				if(sourceFile[i] == '/' && sourceFile[i+1] == '/') {
					i += 2;
					while(sourceFile[i] != '\n') {
						i++;
					}
				}
				if(sourceFile[i] == '/' && sourceFile[i+1] == '*') {
					i=i+2;
					while(sourceFile[i] !='*' || sourceFile[i+1] != '/') {
						i++;
						if(i==(sourceFile.length-1)) {
							System.out.println("注释有误，未找到注释尾");
							return output;
						}
					}
					i=i+2;
				}
				if(sourceFile[i] != '\n' && sourceFile[i] != '\r' && sourceFile[i] != '\t') {
					output[index]=sourceFile[i];
					index++;
				}
			}
			index++;
			output[index]='\0';
		}
		return output;
	}
	
	public boolean isDigit(char c){
		if(c >= '0' && c <= '9'){
			return true;
		}
		return false;
	}
	
	public boolean isLetter(char c) {
		if((c >= 'a' && c <= 'z')||(c >= 'A' && c < 'Z')) {
			return true;
		}
		return false;
	} 
	
	public int isReserve(String s,String []reserve) {
		int index = -1;
		for(int i=0; i<reserve.length; i++) {
			if(s.equals(reserve[i] + "")) {
				index = i;
				break;
			}
		}
		return index;
	}
	
	public int isOperator(String s,String []operator) {
		int index=-1;
		for(int i=0; i<operator.length; i++) {
			if(s.equals(operator[i] + "")) {
				index = i;
				break;
			}
		}
		return index;
	}
	
	public int isDivide(String s,char []divide) {
		int index=-1;
		for(int i=0; i<divide.length; i++) {
			if(s.equals(divide[i] + "")) {
				index = i;
				break;
			}
		}
		return index;
	}
	
	public String index2String(String listName, int index) {
		switch(listName) {
			case "reserve":
				switch(index) {
					case 0:
						return "NEW";
					case 1:
						return "IF";
					case 2:
						return "ELSE";
					case 3:
						return "WHILE";
					case 4:
						return "THROW";
					case 5:
						return "THIS";
					case 6:
						return "INT";
					case 7:
						return "STRING";
					case 8:
						return "CHAR";
					case 9:
						return "DOUBLE";
					case 10:
						return "FLOAT";
					case 11:
						return "STATIC";
					case 12:
						return "PUBLIC";
					case 13:
						return "PRIVATE";
					case 14:
						return "DEFAULT";
					case 15:
						return "SWITCH";
					case 16:
						return "CATCH";
					case 17:
						return "VOID";
					case 18:
						return "TRY";
					case 19:
						return "RETURN";
					case 20:
						return "CLASS";
				}
			case "operator":
				switch(index) {
					case 0:
						return "ASSIGN";
					case 1:
						return "ADD";
					case 2:
						return "MINUS";
					case 3:
						return "MULTIPLY";
					case 4:
						return "DIVIDE";
					case 5:
						return "ADD ADD";
					case 6:
						return "MINUS MINUS";
					case 7:
						return "EQU";
					case 8:
						return "NOT EQU";
					case 9:
						return "GTR";
					case 10:
						return "LES";
					case 11:
						return "GTR EQU";
					case 12:
						return "LES EQU";
					case 13:
						return "AND";
					case 14:
						return "OR";
					case 15:
						return "NOT";
					case 16:
						return "MEMBER OPERATOR";
				}
			case "divide":
				switch(index) {
					case 0:
						return "LEFT_BRACKET";
					case 1:
						return "RIGHT_BRACKET";
					case 2:
						return "LEFT_PARENTHESIS";
					case 3:
						return "RIGHT_PARENTHESIS";
					case 4:
						return "LEFT_BRACE";
					case 5:
						return "RIGHT_BRACE";
					case 6:
						return "LEFT_SQUARE_BRACKET";
					case 7:
						return "RIGHT_SQUARE_BRACKET";
					case 8:
						return "QUOTES";
					case 9:
						return "COMMA";
					case 10:
						return "SEMICOLON";
				}
		}
		return ""; 
	}
	
	public void compile() throws IOException {
		System.out.println("读取文件中......");
		String sourceStr = file2String(this.file);
		System.out.println(sourceStr);
		System.out.println("读取文件完毕");
		System.out.println("去除注释......");
		char[] afterTreatment = preTreatment(sourceStr.toCharArray());
		System.out.println("去除注释完毕");
		System.out.println("------------Lexical Analysis Begin!------------");
		System.out.format("单词序号" + "%10s" + "单词字符串" + "%20s " + "单词类型" + "%20s" + "单词值\n", space, space, space);
		String temp="";
		int index = 0;
		while(afterTreatment[index] != '\0'){
			if(isLetter(afterTreatment[index])) {
				temp += afterTreatment[index];
				if(index >= 1) {
					if(afterTreatment[index-1] == '"') {
						while(isLetter(afterTreatment[index+1])|| isDigit(afterTreatment[index+1])) {
							index ++;
							temp += afterTreatment[index];
						}
						System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, STRING, temp);
						no ++;
					} else {
						while(isLetter(afterTreatment[index+1]) || isDigit(afterTreatment[index+1])) {
							index++;
							temp += afterTreatment[index];
						}
						tempIndex = isReserve(temp, reserve);
						if(tempIndex != -1) {
							System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, index2String("reserve", tempIndex), temp);
							no ++;
						} else {
							System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, IDENTIFIER, temp);
							no ++;
						}
					}
				} else {
					while(isLetter(afterTreatment[index+1]) || isDigit(afterTreatment[index+1])) {
						index++;
						temp += afterTreatment[index];
					}
					tempIndex = isReserve(temp, reserve);
					if(tempIndex != -1) {
						System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, index2String("reserve", tempIndex), temp);
						no ++;
					} else {
						System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, IDENTIFIER, temp);
						no ++;
					}
				}
				
			} else if(isDigit(afterTreatment[index])) {
				temp += afterTreatment[index];
				while(isDigit(afterTreatment[index+1])) {
					index++;
					temp += afterTreatment[index];
				}
				if(afterTreatment[index+1] == '.') {
					index++;
					if(!isDigit(afterTreatment[index+1])){
						System.out.println("Error!小数点后无数字!");
						temp="";
						break;
					} else {
						temp+=afterTreatment[index];
						while(isDigit(afterTreatment[index+1])) {
							index++;
							temp+=afterTreatment[index];
						}
					}
					System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, DECIMALS, temp);
					no ++;
				} else {
					System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, INTEGER, temp);
					no ++;
				}
			} else if(afterTreatment[index] != ' ') {
				temp+=afterTreatment[index];
				tempIndex = isDivide(temp, divide);
				if(tempIndex != -1){
					System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, index2String("divide", tempIndex), temp);
					no ++;
					temp="";
					index++;
					continue;
				} else {
					while((isDivide(afterTreatment[index+1]+"", divide)==-1)&&(isDigit(afterTreatment[index+1])==false)
							&&(isLetter(afterTreatment[index+1])==false)) {
						if(afterTreatment[index+1] != ' ') {
							temp+=afterTreatment[index];
						}
						index ++;
						
					}
					tempIndex = isOperator(temp, operator);
					if(tempIndex != -1) {
						
						System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, index2String("operator", tempIndex), temp);
						no ++;
					} else {
						System.out.format("%5d%10s"+"%20s"+"%10s\n", no, temp, ERROR, temp);
						no ++;
					}
				}
				
			} 
			temp="";
			index++;
		}
		System.out.println("------------Lexical Analysis Finished!------------");
	}
	
	public static void main(String[] args) throws IOException {
		
		PL1Compiler compiler = new PL1Compiler(new File("C:\\Users\\pc\\eclipse-workspace\\Algorithm\\src\\编译原理\\data.p1"));
		
		compiler.compile();
	}

}
