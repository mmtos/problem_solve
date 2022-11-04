package acmicpc;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1780 {
    private static final String pNum = "P1780";
    private static final int[] cnt = new int[3]; //0,1,2
    private static int[][] bigPaper;

    public static void main(String[] args) throws Exception {
        // #분할정복
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inputPath + pNum)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        bigPaper = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                bigPaper[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        solve(0, 0, N);
        for (int a : cnt) {
            System.out.println(a);
        }
    }

    //재귀함수.  x, y는 종이의 좌측상단 시작점.
    static void solve(int x, int y, int n) {
        //정복
        if (same(x, y, n)) {
            cnt[bigPaper[x][y] + 1] += 1;
            return;
        }

        //분할
        int m = n / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                solve(x + i * m, y + j * m, m);
            }
        }
    }

    static boolean same(int x, int y, int n) {
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (bigPaper[x][y] != bigPaper[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    static void test() {
        int size = 9;
        bigPaper = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                bigPaper[i][j] = 0;
            }
        }
        //bigPaper[2][1] = -1;
        System.out.println(same(0, 0, size));
    }
}
