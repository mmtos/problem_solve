package acmicpc;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class P14889 {
    public static void main(String[] args) throws Exception {
        // #브루트
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        Scanner scan = new Scanner(new File(inputPath + "P14889"));

        int N = scan.nextInt();
        int[][] sinergy = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sinergy[i][j] = scan.nextInt();
            }
        }
        //System.out.println(Arrays.deepToString(sinergy));

        int[] teamChoice = new int[N];
        for (int i = 0; i < teamChoice.length; i++) {
            if (i < N / 2) {
                teamChoice[i] = 0;
            } else {
                teamChoice[i] = 1;
            }
        }
        int[] team1 = new int[N / 2];
        int[] team2 = new int[N / 2];
        int minDiff = Integer.MAX_VALUE;
        do {
            int team1Index = 0;
            int team2Index = 0;

            for (int i = 0; i < teamChoice.length; i++) {
                if (teamChoice[i] == 0) {
                    team1[team1Index++] = i;
                } else {
                    team2[team2Index++] = i;
                }
            }
            int team1Stat = calcStat(team1, sinergy);
            int team2Stat = calcStat(team2, sinergy);
            int diff = Math.abs(team1Stat - team2Stat);
            if (diff < minDiff) {
                minDiff = diff;
            }
        } while (next(teamChoice));
        System.out.println(minDiff);
        scan.close();
    }

    static int calcStat(int[] team, int[][] sinergy) {
        int sum = 0;
        for (int i = 0; i < team.length - 1; i++) {
            for (int j = i + 1; j < team.length; j++) {
                sum += sinergy[team[i]][team[j]];
                sum += sinergy[team[j]][team[i]];
            }
        }
        return sum;
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
