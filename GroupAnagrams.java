import java.util.*;

public class GroupAnagrams {
    public static List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        HashMap<String, List<String>> map = new HashMap<>();
        String[] strs2 = new String[strs.length];

        for (int i = 0; i < strs.length; i++) {
            char[] temp = strs[i].toCharArray();
            Arrays.sort(temp);
            strs2[i] = new String(temp);
        }

        for (int i = 0; i < strs.length; i++) {
            if (!map.containsKey(strs2[i])) {
                map.put(strs2[i], new ArrayList<String>());
            }
            map.get(strs2[i]).add(strs[i]);
        }

        for (Map.Entry<String, List<String>> set : map.entrySet()) {
            ans.add(set.getValue());

        }

        return ans;
    }

}
