import java.util.*;
public class LongestConsecutiveSequence{
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i<nums.length; i++){
            set.add(nums[i]);
        }

        int length = 0;
        int answer = 0;

        for (int i = 0; i<nums.length; i++){
            // if its a start of a sequence
            if (!set.contains(nums[i] - 1)){
                length = 1;
                while(set.contains(nums[i] + length)){
                    length++;
                }
                answer = Math.max(answer, length);
            }
        }




        return answer;
    }
}