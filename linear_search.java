import java.util.Scanner;

public class linear_search {
   public static void main(String[] args) {
      if (args.length != 2) usage();

      int set_length = Integer.parseInt(args[0]);
      int length = Integer.parseInt(args[1]);
      
      Scanner scanner = new Scanner(System.in);

      for (int i = 0; i < set_length; ++i) {
         // reading data for each search.
         int x = scanner.nextInt(); // reading x from stdin.
         int[] array = new int[length];
         for (int j = 0; j < length; ++j) {
            array[j] = scanner.nextInt();
         }

         // mark starting time
         long start = System.nanoTime();
         linearSearch(x, array);
         // mark end time
         long end = System.nanoTime();
         // calc delta
         long delta = end - start;
         // print delta on stdout.

         System.out.println(delta + " ns elapsed");
      }

      scanner.close();
   }

   public static int linearSearch(int x, int array[]) {
      int n = array.length;
      for (int i = 0; i < n; ++i) {
         if (array[i] == x) return i;
      }
      return -1;
   }

   public static void usage() {
      System.err.println("usage: java linear_search <set_length> <length>");
      System.err.println("reads from standard instream <set_lenght> rows formated as: x array[<length>]");
      System.err.println("where \"x\" is a value in the array and \"array\" is an array with lenght <lenght>");
      System.err.println("prints at stdout time elapsed for each linear search of x at array");
      System.exit(0);
   }
}