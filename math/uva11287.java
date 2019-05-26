import java.util.Scanner;
import java.math.BigInteger;

 class uva11287 {
	public static void main(String[] args) {
//      System.out.println("Hello World"); // prints Hello World

      Scanner reader = new Scanner(System.in);  // Reading from System.in

      BigInteger p = reader.nextBigInteger(); // Scans the next token of the input as an int.
      BigInteger a = reader.nextBigInteger();
      int counter = 0;
      while (a.compareTo(BigInteger.ZERO) != 0 && p.compareTo(BigInteger.ZERO) != 0) {

          if (a.modPow(p, p).compareTo(a) == 0 &&  !p.isProbablePrime(10))
              System.out.println("yes");
          else
              System.out.println("no");
          p = reader.nextBigInteger(); // Scans the next token of the input as an int.
          a = reader.nextBigInteger();
      }
      reader.close();
   }
}
