import java.util.*;

public class HappyNumber {

    public static boolean isHappy(int n) {
        Set<Integer> list = new HashSet<Integer>();

        while (!list.contains(n)) {

            list.add(n);

            n = getNext(n);

            if (n == 1) {
                return true;
            }

        }

        return false;
    }

    public static int getNext(int n) {

        int sum = 0;

        while (n > 0) {
            int y = n % 10;

            sum += Math.pow(y, 2);

            n /= 10;
        }

        return sum;
    }


    public static void main(String[] args){
        int n = 19;

        isHappy(n);
    }

}
