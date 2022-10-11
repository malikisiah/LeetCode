import java.util.*;

public class PlusOne {
    public int[] plusOne(int[] digits) {

        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] = digits[i] + 1;

                return digits;
            }

            else {
                digits[i] = 0;

            }
        }

        int[] temp = Arrays.copyOf(digits, digits.length + 1);

        temp[temp.length - 1] = 1;

        int[] result = new int[temp.length];

        for (int i = temp.length - 1, j = 0; i >= 0; i--, j++) {
            result[j] = temp[i];
        }

        return result;
    }
}
