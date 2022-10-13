import java.util.*;

public class ThreeSum {
    public static List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums);

        for (int x = 0; x < n - 2; x++) {
            if (x == 0 || (x > 0 && nums[x] != nums[x - 1])) {
                int target = 0 - nums[x];
                int y = x + 1;
                int z = n - 1;

                while (y < z) {
                    if (nums[y] + nums[z] == target) {
                        ArrayList<Integer> values = new ArrayList<>();
                        values.add(nums[x]);
                        values.add(nums[y]);
                        values.add(nums[z]);

                        list.add(values);

                        while (y < z && nums[y] == nums[y + 1]) {
                            y++;
                        }

                        while (y < z && nums[z] == nums[z - 1]) {
                            z--;
                        }
                        y++;
                        z--;
                    }

                    else if (nums[y] + nums[z] > target) {
                        z--;
                    } else {
                        y++;
                    }

                }
            }

        }

        return list;

    }

    public static void main(String[] args) {
        int[] nums = { -1, 0, 1, 2, -1, -4 };
        threeSum(nums);

    }
}
