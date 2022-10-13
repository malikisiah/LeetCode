public class ContainerMostWater {
    public int maxArea(int[] height) {

        int ans = 0;
        int left = 0;
        int right = height.length - 1;

        while (left < right) {
            if (height[left] >= height[right]) {
                int x = right - left;
                int y = Math.min(height[left], height[right]);

                int area = x * y;
                ans = Math.max(ans, area);
            }

            if (left < right) {
                left++;
            }

            else {
                right--;
            }

        }

        return ans;
    }
}
