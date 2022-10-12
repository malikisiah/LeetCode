
public class twoSum2 {
    public int[] twoSum(int[] numbers, int target) {
        int[] ans = new int[2];

        int i = 0;
        int j = numbers.length - 1;

        while (i < numbers.length || j >= 0) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            }

            if (numbers[i] + numbers[j] < target) {
                i++;
            }

            if (numbers[i] + numbers[j] == target) {
                ans[0] = i + 1;
                ans[1] = i + 2;
                return ans;
            }
        }

        return ans;

    }

}
