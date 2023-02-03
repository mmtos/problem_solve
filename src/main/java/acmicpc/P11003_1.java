package acmicpc;

import java.util.*;

import java.io.*;

public class P11003_1 {
    static int N,L;
    static Deque<Pair> D = new ArrayDeque<>();

    public static void main(String[] args) throws Exception {
        //#덱 #답지
        // LinkedList 대신 ArrayDeque로, JAVA 11로 돌리니 맞았음
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            L = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for(int i=0;i < N; i++){
                // 덱이 꼭 L만큼의 원소를 가질 필요는 없다. 원소개수만큼 반복하며 최소값만 찍으면 됨
                int next = Integer.parseInt(st.nextToken());
                while(!D.isEmpty() && D.peekLast().y >= next) D.pollLast();
                // L보다 오래된 숫자를 제거하기 위해 인덱스도 같이 저장한다.
                D.addLast(new Pair(i, next));
                while(D.peekFirst().x <= i - L) D.pollFirst();
                bw.write(D.peekFirst().y + " ");
            }
            bw.flush();
        }
    }

    static class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) {
                return true;
            }
            if (o == null || getClass() != o.getClass()) {
                return false;
            }
            P3190.Pair pair = (P3190.Pair) o;
            return x == pair.x && y == pair.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }
}
