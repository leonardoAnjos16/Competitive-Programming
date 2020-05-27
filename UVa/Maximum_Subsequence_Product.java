import java.math.BigInteger;
import java.util.Scanner;

public class Maximum_Subsequence_Product {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        BigInteger delim = new BigInteger("-999999");
        BigInteger zero = new BigInteger("0");

        while (in.hasNextBigInteger()) {
            BigInteger A[] = new BigInteger[105];
            int length = 0;

            do A[length] = in.nextBigInteger();
            while (A[length++].compareTo(delim) != 0);

            BigInteger prod[] = new BigInteger[105];
            prod[0] = new BigInteger("1"); length--;

            boolean hasZero = false;
            for (int i = 1; i <= length; i++) {
                if (A[i - 1].compareTo(zero) == 0) {
                    prod[i] = new BigInteger("1");
                    hasZero = true;
                }
                else prod[i] = prod[i - 1].multiply(A[i - 1]);
            }

            BigInteger ans = hasZero ? new BigInteger("0") : new BigInteger("-1000000");
            for (int i = 1; i <= length; i++) {
                if (A[i - 1].compareTo(zero) == 0) continue;
                for (int j = i; j <= length && A[j - 1].compareTo(zero) != 0; j++)
                    if (ans.compareTo(prod[j].divide(prod[i - 1])) < 0)
                        ans = prod[j].divide(prod[i - 1]);
            }

            System.out.println(ans.toString(10));
        }

        in.close();
    }
}