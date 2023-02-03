package acmicpc;

import acmicpc.P10871.Pair;
import java.io.*;
import java.util.*;

public class P3190 {
    static int N,K,L;
    static final int APPLE = 2;
    static int[][] map = new int[101][101];
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    // 좌표평면 상 x축의 이동은 행렬에서 열 방향의 이동임. 헷갈리지 말것.
    static int direction = 2;
    static Deque<Pair> snake = new LinkedList<>();
    static Queue<Pair> cd = new LinkedList<>();
    static {
        snake.addFirst(new Pair(1,1));
    }
    static void changeDirection(int dc){
        switch (direction){
            case 0:
                direction = dc == 'L' ? 2:3;
                break;
            case 1:
                direction = dc == 'L' ? 3:2;
                break;
            case 2:
                direction = dc == 'L' ? 1:0;
                break;
            case 3:
                direction = dc == 'L' ? 0:1;
                break;
            default:
                break;
        }
    }
    public static void main(String[] args) throws Exception {
        // #큐
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            N = Integer.parseInt(br.readLine());
            K = Integer.parseInt(br.readLine());
            StringTokenizer st = null;
            while(K-- > 0){
                st = new StringTokenizer(br.readLine());
                map[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = APPLE;
            }
            L = Integer.parseInt(br.readLine());
            while(L-- > 0){
                st = new StringTokenizer(br.readLine());
                cd.offer(new Pair(Integer.parseInt(st.nextToken()),st.nextToken().charAt(0)));
            }

            int now = 0;
            while(now++ >= 0){
                System.out.println(now + "," + direction);
                Pair head = snake.peekFirst();
                Pair next = new Pair(head.x + dx[direction],head.y + dy[direction]);
                if(next.x > N || next.y > N  || next.x <= 0 || next.y <= 0 || snake.contains(next)) break;
                if(map[next.x][next.y] == APPLE){
                    snake.addFirst(next);
                    map[next.x][next.y] = 0;
                }else {
                    snake.addFirst(next);
                    snake.pollLast();
                }
                //방향전환
                System.out.println(now + "," + snake.peekFirst());
                if(!cd.isEmpty() && cd.peek().x == now) changeDirection(cd.poll().y);

            }
            System.out.println(now);
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
            Pair pair = (Pair) o;
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
