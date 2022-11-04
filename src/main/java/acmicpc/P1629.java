package acmicpc;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1629 {
    private static final String pNum = "P1629";

    public static void main(String[] args) throws Exception {
        // #분할정복
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inputPath + pNum)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int answer = 1;
        for (int i = 0; i < B; i++) {
            answer = (int) (((long) (answer % C) * (A % C)) % C);
        }
        System.out.println(answer);
        System.out.println(solve(A, B, C));
    }

    private static int solve(int A, int B, int C) {
        if (B == 0) {
            return 1;
        }
        if (B == 1) {
            return A;
        }

        int halfProblem = solve(A, B / 2, C);
        if (B % 2 == 0) {
            return (int) (((long) (halfProblem % C) * (halfProblem % C)) % C);
        }

        return (int) (
                (
                        (
                                (
                                        (long) (halfProblem % C) * (halfProblem % C)
                                ) % C
                        ) * (A % C)
                ) % C
        );
    }
}
