package acmicpc;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P2343 {
    private static final String pNum = "P2343";
    private static int N, M;
    private static int[] sum;

    public static void main(String[] args) throws Exception {
        // #이분탐색
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inputPath + pNum)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());//레슨 개수
        M = Integer.parseInt(st.nextToken());//블루레이 갯수
        st = new StringTokenizer(br.readLine());
        int[] lessonTimes = new int[N + 1];
        sum = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            lessonTimes[i] = Integer.parseInt(st.nextToken());
            sum[i] = sum[i - 1] + lessonTimes[i];
        }
        int left = 1;
        int right = 1000000000;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            System.out.println(mid + "mid");
            if (check(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(ans);
    }

    static boolean check(int bluelaySize) {
        //복사
        int bluelayCount = M;
        int index = 1;
        int nextIndex = 1;
        while (bluelayCount != 0 && nextIndex != sum.length) {
            while (nextIndex != sum.length && (bluelaySize >= sum[nextIndex] - sum[index - 1])) {
                nextIndex++;
            }
            index = nextIndex;
            bluelayCount--;
            System.out.println(bluelayCount + " " + nextIndex + " " + index);
        }
        //다 담지 못하면.
        return nextIndex == sum.length;
    }
}
