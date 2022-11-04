package acmicpc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class P1339 {
    public static void main(String[] args) throws Exception {
        // #브루트
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        Scanner scan = new Scanner(new File(inputPath + "P1339"));

        //int[] alphaArr = {0,1,2,3,4,5,6,7,8,9}; // 나오지 않는 알파벳까지 반복하는건 비효율적.
        Map<Character, Integer> alphaMap = new HashMap<>();
        int wordCount = Integer.parseInt(scan.nextLine());
        int alphaCount = 0;
        String[] wordList = new String[wordCount];
        for (int i = 0; i < wordCount; i++) {
            String word = scan.nextLine();
            wordList[i] = word;
            for (int j = 0; j < word.length(); j++) {
                //A:65
                if (alphaMap.get(word.charAt(j)) == null) {
                    alphaMap.put(word.charAt(j), alphaCount++);
                }
            }
        }
        int[] alphaArr = new int[alphaCount];
        for (int i = 0; i < alphaArr.length; i++) {
            alphaArr[i] = 9 - i;
        }
        Arrays.sort(alphaArr);
        int max = Integer.MIN_VALUE;
        do {
            int sum = 0;
            for (String wi : wordList) {
                int now = 0;
                for (int i = 0; i < wi.length(); i++) {
                    now = 10 * now + alphaArr[alphaMap.get(wi.charAt(i))];
                }
                sum += now;
            }

            if (sum > max) {
                max = sum;
            }
        } while (next(alphaArr));
        System.out.println(max);
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
