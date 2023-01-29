package Solution;

import java.util.ArrayList;

public class Solution {

    public static float solution(int[] a, int[] b) {
        ArrayList<Integer> merged = new ArrayList<Integer>();

        for (int i: a) {
            merged.add(i);
        }
        for (int i : b) {
            merged.add(i);
        }

        final float sum = merged.stream().mapToInt(Integer::intValue).sum();

        return sum/merged.size();
    }
}
