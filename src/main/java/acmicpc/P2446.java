package acmicpc;

import java.util.*;
public class P2446 {
    static int X;
    public static void main(String[] args) {
        //#구현
        Scanner sc = new Scanner(System.in);
        X = sc.nextInt();
        for(int i=X; i>0; i--){
            for(int j=0;j<X-i;j++){
                System.out.print(" ");
            }
            for(int j=0;j<2*i-1;j++){
                System.out.print("*");
            }
            System.out.println();
        }
        for(int i=1; i<X; i++){
            for(int j=1;j<X-i;j++){
                System.out.print(" ");
            }
            for(int j=0;j<2*i+1;j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
