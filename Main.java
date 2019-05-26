import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	 public static void main (String args[])  // entry point from OS
	    {
	        Main myWork = new Main();  // create a dinamic instance
	        myWork.Begin();            // the true entry point
	    }

	    void Begin()
	    {
	        Scanner reader = new Scanner(System.in);  // Reading from System.in
	        int num_of_tests = reader.nextInt();
	        reader.nextLine();

	        for (int i = 0; i < num_of_tests; i++) {

	            String line = reader.nextLine();
	            String vec[] = line.split("[.]");
	            String fullnum;
	            int exponent_a;
	            if (vec.length == 1) {
                	exponent_a = 0;
                	fullnum = vec[0];
                }
                else {
                	exponent_a = vec[1].length();
                	fullnum = vec[0] + vec[1];
                }


	            BigInteger a = new BigInteger(fullnum);

	            while (true) {
	                int exponent_b;
	                BigInteger b;

	                line = reader.nextLine();
	                Scanner sc = new Scanner(line);
	                if (sc.hasNextInt() && sc.nextInt() == 0) break;
                    vec = line.split("[.]");
                    if (vec.length == 1) {
                    	exponent_b = 0;
                    	fullnum = vec[0];
                    }
                    else {
                    	exponent_b = vec[1].length();
                    	fullnum = vec[0] + vec[1];
                    }


                    b = new BigInteger(fullnum);

	                if (exponent_a > exponent_b) {
	                    b = b.multiply(BigInteger.TEN.pow(exponent_a - exponent_b));
	                    a = a.add(b);
	                }
	                else if (exponent_a < exponent_b) {
	                    a = a.multiply(BigInteger.TEN.pow(exponent_b - exponent_a));
	                    a = a.add(b);
	                    exponent_a = exponent_b;
	                }
	                else {
	                    a = a.add(b);
	                }
	                sc.close();
	            }

	            String result = a.toString();
	            if (result.charAt(0) == '-') {
	            	System.out.print("-");
	            	a = a.abs();
	            }
	            result = a.toString();
	            if(result == "0") {
	            	System.out.println("0");
	            }
	            else {
	            	int ref = result.length();
		            int aux = ref - exponent_a;
		            if (aux <= 0) {
		            	System.out.print("0.");
		            	while (aux++ != 0) System.out.print("0");
		            	System.out.println(result);
		            }
		            else {
		            	boolean dont_print_dot = false;
		            	String first = result.substring(0, aux);
			            String second = result.substring(aux, ref);
			            int index = second.length();
			            while (second.charAt(--index) == '0') {
			            	if (index == 0) {
			            		dont_print_dot = true;
			            		break;
			            	}
			            }
			            index++;
			            second = second.substring(0, index);
			            System.out.print(first);
			            if (dont_print_dot) {
			            	System.out.println("");
			            }
			            else {
			            	System.out.println('.' + second);
			            }
		            }
	            }


	        }
	        reader.close();
	    }
}
