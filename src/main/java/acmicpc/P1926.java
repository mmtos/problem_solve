package acmicpc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P1926 {
    final int MAX_N = 501;
    int[][] map = new int[MAX_N][MAX_N];
    int[][] vis = new int[MAX_N][MAX_N];
    // 행, 열
    int N,M;
    int[] dx = {1,-1,0,0};
    int[] dy = {0,0,1,-1};

    class Pair{
        int x,y;
        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    Pair pair(int x, int y){
        return new Pair(x,y);
    }

    void solve() throws Exception{
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            Queue<Pair> Q = new LinkedList<>();
            int count = 0, maxArea = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if(vis[i][j] != 0) continue;
                    if(map[i][j] == 0) continue;
                    count++;
                    int area = 0;
                    Q.offer(pair(i,j));
                    vis[i][j] = 1;
                    area++;
                    while(!Q.isEmpty()){
                        Pair next = Q.poll();
                        for (int k = 0; k < 4; k++) {
                            int nx = next.x + dx[k];
                            int ny = next.y + dy[k];
                            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                            if(vis[nx][ny] != 0) continue;
                            if(map[nx][ny] == 0) continue;
                            Q.offer(pair(nx,ny));
                            vis[nx][ny] = 1;
                            area++;
                        }
                    }
                    maxArea = Math.max(maxArea,area);
                }
            }
            System.out.println(count);
            System.out.println(maxArea);
        }
    }

    public static void main(String[] args) throws Exception {
        // #BFS #플러드필
        (new P1926()).solve();
    }
}
