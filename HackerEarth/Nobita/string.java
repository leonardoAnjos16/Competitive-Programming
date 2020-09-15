import java.util.Scanner;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner in = new Scanner(System.in);
        
        int numCases = in.nextInt();
        in.nextLine();
        for (int i = 0; i < numCases; i++) {
            String[] sentence = in.nextLine().split(" ");
            
            for (int j = sentence.length - 1; j >= 0; j--)
                System.out.print(sentence[j] + " ");
                
            System.out.println();
        }

        in.close();
    }
}