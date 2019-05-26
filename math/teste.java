import java.util.Scanner;
import java.math.BigInteger;


public class teste {

   /* This is my first java program.
    * This will print 'Hello World' as the output
    */

   public static void main(String[] args) {
      // System.out.println("Hello World"); // prints Hello World

      Scanner reader = new Scanner(System.in);  // Reading from System.in

      BigInteger p = reader.nextBigInteger(); // Scans the next token of the input as an int.
      BigInteger a = reader.nextBigInteger();
      System.out.println(a.modPow(p, p));

      reader.close();
   }
}
