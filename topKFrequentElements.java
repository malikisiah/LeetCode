import java.util.*;

public class topKFrequentElements {

    public static int[] topKFrequent(int[] nums, int k) {
        int[] ans = new int[k];
        HashMap<Integer, Integer> map = new HashMap<>();
        PriorityQueue<Map.Entry<Integer, Integer>> pQueue = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());

        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], 1);
            }

            else {
                map.put(nums[i], map.get(nums[i]) + 1);
            }
        }

        for (Map.Entry<Integer, Integer> it : map.entrySet()) {
            pQueue.add(it);
            if (pQueue.size() > k) {
                pQueue.poll();
            }

        }

        int i = k;
        while (!pQueue.isEmpty()) {
            ans[--i] = pQueue.poll().getKey();
        }

        return ans;

    }

}
