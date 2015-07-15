import java.util.* ;
public class permutations {
		
		
  public static ArrayList<String> getperms(String s){
	  ArrayList<String> arr = new ArrayList<String>();
	  
	  if(s==null){
		  return null;
	  }
	  else if(s.length()==0){
		  arr.add("");
		  return arr;
	  }
	  char first = s.charAt(0);
	  
	  String remainder = s.substring(1);
	  
	  ArrayList<String> words = getperms(remainder);
	  
	  for(String word : words){
	  //	  System.out.println(remainder+" "+word);
		  for(int j=0;j<=word.length();j++){
			  arr.add(insertcharat(word,first,j));
		  }
	  }

	  for(String a : arr)
	  	System.out.println(a);
	  return arr;
  }
  
  
  public static String  insertcharat(String word, char c, int i){
	  String start = word.substring(0,i);
	  String end = word.substring(i);
	  //System.out.println("insert" + " "+start+c+end);
	  return start+c+end;
  }
  		
	public static void main(String[] args){	
		String s = "abcd";
		ArrayList<String> perm = new ArrayList<String>();
	
		perm = getperms(s);

		System.out.println("helloworld");
		
		for(String perms:perm)
			System.out.print(perms+" ");
	}
	
}
