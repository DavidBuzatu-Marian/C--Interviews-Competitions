package LeetCode;

import java.util.HashMap;
import java.util.Map;

class SumIII {
    HashMap<Integer, Integer> table = new HashMap<>();

    public void add(Integer val) {
        table.put(val, table.getOrDefault(val, 0) + 1);
    }

    public boolean find(int val) {
        for (Map.Entry<Integer, Integer> entry : table.entrySet()) {
            int searched = val - entry.getKey();
            if (searched == val) {
                if (entry.getValue() >= 2) {
                    return true;
                }
            } else if (table.containsKey(searched)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {

    }
}