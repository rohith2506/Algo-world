import java.util.* ;

public class parantheses{

	public static void printpar(int left,int right,char[] str,int count){
			if (left < 0 || right < 0) return;

			else if(left == 0 && right == 0)
				System.out.println(str);

			else{
				if(left>0){
					str[count]='(';
					printpar(left-1,right,str,count+1);
				}
				if(right>1){
					str[count]=')';
					printpar(left,right-1,str,count+1);
				}
			}
	}

	public static void main(String[] args){
		int count = 3;
		char[] str = new char[count*2];
		System.out.println("Hello");
		printpar(count,count,str,0);
		System.out.println("Hello");
	}
} 