package acmicpc;

import java.util.*;
import java.util.stream.*;

public class P2164 {
    public static void main(String[] args) {
        //#큐
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Queue<Integer> list = IntStream.rangeClosed(1,N).boxed()
                .collect(Collectors.toCollection(LinkedList::new));
        while(list.size() != 1){
            list.poll();
            list.offer(list.poll());
        }
        System.out.println(list.element());
    }
}
