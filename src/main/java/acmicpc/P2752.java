package acmicpc;

import java.util.Scanner;
import java.util.TreeSet;

public class P2752 {
    public static void main(String[] args) {
        //#구현, #정렬
        Scanner sc = new Scanner(System.in);
        TreeSet<Integer> intTree = new TreeSet<>();
        for(int i=0; i<3;i++){
            intTree.add(sc.nextInt());
        }
        for (Integer i : intTree) {
            System.out.print(i + " ");
        }
    }
}
