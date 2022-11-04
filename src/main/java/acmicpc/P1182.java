package acmicpc;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1182 {
    public static void main(String[] args) throws Exception {
        // #브루트
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        //부분수열의 부분수열에 대한 합을 미리 저장해놓아도 상관없.
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inputPath + "P1182")));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int S = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] numArr = new int[N];
        for (int i = 0; i < N; i++) {
            numArr[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(bruteSearch(numArr, 0, 0, S));
    }

    static int bruteSearch(int[] arr, int index, int status, int targetSum) {
        if (index == arr.length) {
            if (status == 0) {
                return 0;
            }
            int sum = 0;
            for (int i = 0; i < arr.length; i++) {
                if ((status & (int) Math.pow(2, i)) == (int) Math.pow(2, i)) {
                    System.out.println("sum:" + i + ":" + arr[i]);
                    sum += arr[i];
                }
            }
            if (sum == targetSum) {
                return 1;
            } else {
                return 0;
            }
        }
        int include = bruteSearch(arr, index + 1, status + (1 << index), targetSum);
        int exclude = bruteSearch(arr, index + 1, status, targetSum);

        return include + exclude;
    }

}
