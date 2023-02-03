package acmicpc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P7569 {
    final int MAX_N = 101;
    // 행, 열, 높이
    int N,M,H;
    int[][][] vis = new int[MAX_N][MAX_N][MAX_N];
    int[][][] map = new int[MAX_N][MAX_N][MAX_N];
    int[] dx = {1,-1,0,0,0,0};
    int[] dy = {0,0,1,-1,0,0};
    int[] dz = {0,0,0,0,1,-1};

    class Tuple{
        int x,y,z;

        public Tuple(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }
    void solve() throws Exception{
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            Queue<Tuple> Q = new LinkedList<>();
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < M; k++) {
                        vis[j][k][i] = -1;
                    }
                }
            }

            for (int i = 0; i < H; i++) {
                for (int j = 0; j < N; j++) {
                    st = new StringTokenizer(br.readLine());
                    for (int k = 0; k < M; k++) {
                        int value = Integer.parseInt(st.nextToken());
                        map[j][k][i] = value;
                        if(value == 1){
                            Q.offer(new Tuple(j,k,i));
                            vis[j][k][i] = 0;
                        }
                    }
                }
            }
            while(!Q.isEmpty()){
                Tuple next = Q.poll();
                for (int i = 0; i < 6; i++) {
                    int nx = next.x + dx[i];
                    int ny = next.y + dy[i];
                    int nz = next.z + dz[i];
                    if(nx < 0 || nx >= N) continue;
                    if(ny < 0 || ny >= M) continue;
                    if(nz < 0 || nz >= H) continue;
                    if(vis[nx][ny][nz] >= 0) continue;
                    if(map[nx][ny][nz] == -1) continue;
                    Q.offer(new Tuple(nx,ny,nz));
                    map[nx][ny][nz] = 1;
                    vis[nx][ny][nz] = vis[next.x][next.y][next.z] + 1;
                }
            }
            int maxDist = -1;
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < M; k++) {
                        if(map[j][k][i] == 0) {
                            System.out.println(-1);
                            return;
                        }
                        maxDist = Math.max(maxDist,vis[j][k][i]);
                    }
                }
            }
            System.out.println(maxDist);
        }
    }

    public static void main(String[] args) throws Exception {
        // #BFS #거리
        (new P7569()).solve();
    }
}
