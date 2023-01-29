import Solution.Solution;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<Integer> l1 = new LinkedList<Integer>();
        l1.add(2);
        l1.add(3);
        l1.add(5);

        System.out.println(l1);
        LinkedList<Integer> l2 = new LinkedList<Integer>();
        l2.add(9);
        l2.add(3);
        l2.add(6);

        System.out.println(l2);
        System.out.println("----------");
        System.out.println(Solution.solution(l1, l2));
    }
}