package acmicpc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class P14888 {
    public static void main(String[] args) throws Exception {
        // #브루트
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        Scanner scan = new Scanner(new File(inputPath + "P14888"));

        int N = scan.nextInt();
        int[] numbers = new int[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = scan.nextInt();
        }
        int[] opers = new int[N - 1];
        int index = 0;
        for (int i = 0; i < 4; i++) {
            int operCount = scan.nextInt();
            //+0,-1,*2,/3 순
            for (int j = 0; j < operCount; j++) {
                opers[index++] = i;
            }
        }
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        do {
            int calc = numbers[0];
            for (int i = 0; i < opers.length; i++) {
                if (opers[i] == 0) {
                    calc = calc + numbers[i + 1];
                } else if (opers[i] == 1) {
                    calc = calc - numbers[i + 1];
                } else if (opers[i] == 2) {
                    calc = calc * numbers[i + 1];
                } else if (opers[i] == 3) {
                    calc = calc / numbers[i + 1];
                }
            }
            if (min > calc) {
                min = calc;
            }
            if (max < calc) {
                max = calc;
            }
        } while (next(opers));

        System.out.println(max);
        System.out.println(min);
        scan.close();
    }

    static boolean next(int[] a) {
        int i = a.length - 1;
        while (i > 0 && a[i - 1] >= a[i]) {
            i--;
        }
        if (i == 0) {
            return false;
        }
        int j = a.length - 1;
        while (j > 0 && a[i - 1] >= a[j]) {
            j--;
        }
        int temp = a[i - 1];
        a[i - 1] = a[j];
        a[j] = temp;

        j = a.length - 1;
        while (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
        return true;
    }
}
