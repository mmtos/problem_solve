package acmicpc;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class P1158 {
    static int N, K;
    static LinkedList<Integer> ll;

    static void useBW() throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int idx = K - 1;
        bw.write("<");
        while (!ll.isEmpty()) {
            if (ll.size() == 1) {
                bw.write(String.valueOf(ll.remove()));
                break;
            }
            idx = idx % (ll.size());
            bw.write(ll.remove(idx) + ", ");
            idx += K - 1;
        }
        bw.write(">");
        bw.flush();
        bw.close();
    }

    static void useSB() throws Exception {
        StringBuilder sb = new StringBuilder("<");
        int idx = K - 1;
        while (!ll.isEmpty()) {
            if (ll.size() == 1) {
                sb.append(ll.remove());
                break;
            }
            idx = idx % (ll.size());
            sb.append(ll.remove(idx) + ", ");
            idx += K - 1;
        }
        sb.append(">");
        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {
        //#연결리스트 : 중간 원소를 지워야 하는 연산이 많음.
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        K = scan.nextInt();
        ll = IntStream.rangeClosed(1, N).boxed().collect(Collectors.toCollection(LinkedList::new));
//        useBW();
        useSB();

    }
}
