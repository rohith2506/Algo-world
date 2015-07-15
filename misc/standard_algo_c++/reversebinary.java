import java.util.Scanner;

public class reversebinary{

	public static void main(String[] args){
		 Scanner  Test= new Scanner(System.in);
		 int num = Test.nextInt();
		 System.out.println(reverse(num));
	}

	public static int reverse(int s){
		return Integer.parseInt(new StringBuilder(Integer.toBinaryString(s)).reverse().toString(),2);
	}

}