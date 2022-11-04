package acmicpc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;

public class P10815 {
    private static final String pNum = "P10815";

    public static void main(String[] args) throws Exception {
        // #이분탐색
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inputPath + pNum)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] numArr = new int[N];
        for (int i = 0; i < N; i++) {
            numArr[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        int F = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        shuffle(numArr);
        Arrays.sort(numArr);
        ArrayList<String> answer = new ArrayList<String>();
        for (int i = 0; i < F; i++) {
            String target = st.nextToken();
            if (Arrays.binarySearch(numArr, Integer.parseInt(target)) >= 0) {
                answer.add("1");
            } else {
                answer.add("0");
            }
        }
        System.out.println(String.join(" ", answer));
    }

    static void shuffle(int[] arr) {
        Random random = new Random();
        for (int i = arr.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            int temp = arr[index];
            arr[index] = arr[i];
            arr[i] = temp;
        }
    }
}
