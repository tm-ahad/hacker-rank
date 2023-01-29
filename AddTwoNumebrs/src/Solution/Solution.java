package Solution;

import java.util.LinkedList;
import java.util.function.Consumer;

public class Solution {

    public static LinkedList<Integer> solution(LinkedList<Integer> a, LinkedList<Integer> b) {
        StringBuilder i1 = new StringBuilder();
        StringBuilder i2 = new StringBuilder();

        a.forEach(new Consumer<Integer>() {
            @Override
            public void accept(Integer integer) {
                i1.append(integer);
            }
        });

        b.forEach(new Consumer<Integer>() {
            @Override
            public void accept(Integer integer) {
                i2.append(integer);
            }
        });
        LinkedList<Integer> res = new LinkedList<Integer>();

        String rawres = String.valueOf(Integer.parseInt(i2.toString()) +
                Integer.parseInt(i1.toString()));

        for (int i = 0; i < rawres.length(); i++) {
            String c = String.valueOf(rawres.charAt(i));

            res.add(Integer.parseInt(c));
        }

        return res;
    }
}
