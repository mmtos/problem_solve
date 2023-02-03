package acmicpc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class P11003 {
    static int N,L;
//    static Deque<Integer> D = new ArrayDeque<>(); //시간초과
    static Deque<Integer> D = new LinkedList<>();
    static PriorityQueue<Integer> PQ = new PriorityQueue<>();
    static int MIN = Integer.MAX_VALUE;

    static void tle1() throws Exception{
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            L = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            while(N-- > 0){
                int next = Integer.parseInt(st.nextToken());
                D.addLast(next);
                MIN = Math.min(MIN, next);
                if(D.size() > L && MIN == D.pollFirst()) MIN = Math.min(MIN, Collections.min(D));
                bw.write(MIN + " ");
            }
            bw.flush();
        }
    }

    static void tle2() throws Exception{
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            L = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            while(N-- > 0){
                int next = Integer.parseInt(st.nextToken());
                D.addLast(next);
                PQ.offer(next);
                if(D.size() > L) {
                    PQ.remove(D.pollFirst());
                }
                bw.write(PQ.peek() + " ");
            }
            bw.flush();
        }
    }

    public static void main(String[] args) throws Exception {
        //#덱 #실패
    }
}
