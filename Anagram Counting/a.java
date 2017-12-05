// Meysam Aghighi
import java.math.*;
import java.util.Scanner;


public class Main {
		
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);		
		while (in.hasNext()){
			String s = in.next();
			int [] a = new int[52];
          	int n = s.length();
          	for (int i=0;i<s.length();i++){
              int j;
              if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z')
              	j = s.charAt(i)-'a';
              else j = s.charAt(i)-'A'+26;
              a[j]++;
            }
			BigInteger ans = BigInteger.ONE;
          	for (int i=1;i<=s.length();i++){
              ans = ans.multiply(new BigInteger(i+""));
            }
          	for (int i=0;i<52;i++){
              if (a[i] > 1){
                for (int j=1;j<=a[i];j++)
                  ans = ans.divide(new BigInteger(j+""));
              }
            }
			
			System.out.println(ans);
		}		
	}	
}