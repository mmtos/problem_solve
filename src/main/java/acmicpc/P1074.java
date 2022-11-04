package acmicpc;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1074 {
    private static final String pNum = "P1074";
    private static int r;
    private static int c;

    public static void main(String[] args) throws Exception {
        // #분할정복
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inputPath + pNum)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        solve(N, 0, 0, 0);
        br.close();
    }

    // N=3이고 0,0에서 시작할때 
    // 하위문제에 대한 시작좌표[하위문제 방문 순서]는 다음과 같음
    // (0,0)[0], (0,2^(N-1))[0 + 2^(N-1)] (2^(N-1),0)[0 + 2^(N-1)*2] (2^(N-1),2^(N-1))[0 + 2^(N-1)*3]
    static void solve(int scale, int startX, int startY, int startNumber) {
        if (scale == 0 && startX == r && startY == c) {
            System.out.println(startNumber);
        }
		if (scale == 0) {
			return;
		}

        int cordiStep = (int) Math.pow(2, scale - 1);
        int numberStep = (int) Math.pow(cordiStep, 2);
        if (r < startX + cordiStep) {
            if (c < startY + cordiStep) {
                //좌측상단 사분면만 보면됨
                solve(scale - 1, startX, startY, startNumber);
            } else {
                //우측상단만 보면 됨
                solve(scale - 1, startX, startY + cordiStep, startNumber + numberStep);
            }
        } else {
            if (c < startY + cordiStep) {
                //좌측하단 사분면만 보면됨
                solve(scale - 1, startX + cordiStep, startY, startNumber + numberStep * 2);
            } else {
                //우측하단만 보면 됨
                solve(scale - 1, startX + cordiStep, startY + cordiStep, startNumber + numberStep * 3);
            }
        }
    }
}
