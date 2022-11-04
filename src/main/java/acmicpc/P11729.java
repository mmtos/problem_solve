package acmicpc;

import java.util.Scanner;

public class P11729 {
    private static final String pNum = "P11729";
    private static final StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        // #분할정복
        int from = 1;
        int temp = 2;
        int to = 3;

        Scanner scan = new Scanner(System.in);

        int N = scan.nextInt();
        System.out.println(hanoi(N, from, to, temp));
        System.out.println(sb.toString());
        scan.close();
    }

    static int hanoi(int k, int from, int to, int temp) {
        if (k == 1) {
            sb.append(from + " " + to + "\n");
            return 1;
        }
        int from_temp = hanoi(k - 1, from, temp, to); // from에서 temp로 k-1블록까지 옮기기
        sb.append(from + " " + to + "\n");// from에서To로 k번째 블록 옮기기
        int temp_to = hanoi(k - 1, temp, to, from); //temp에 있는 k-1개 블록 To로 옮기기  
        return from_temp + 1 + temp_to;
    }

}
