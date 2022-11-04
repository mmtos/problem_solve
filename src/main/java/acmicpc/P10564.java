package acmicpc;

import java.util.Arrays;
import java.util.Scanner;

public class P10564 {
    public static void main(String[] args) {
        // #DP
		/*첫째 줄에 테스트 케이스의 개수가 주어지며, 이 값은 1과 20을 포함하는 그 사이의 값이다.

각 테스트 케이스는 두 정수 N과 M (1 ≤ N ≤ 5,000, 1 ≤ M ≤ 10) 으로 시작하며, N은 동혁이가 한 팔굽혀펴기의 횟수, M은 그 경기에서 나올 수 있는 득점의 종류이다.

다음 줄에는  M개의 Si (1 ≤ Si ≤ 20)가 주어지며, 각각의 값은 그 경기에서 팀이 한 번에 득점할 수 있는 점수이다. 모든 점수는 서로 다르다.*/
		/*
		4
		29 3
		7 3 2
		15 1
		1
		16 1
		1
		6 2
		3 1
		
		*/
        Scanner scan = new Scanner(System.in);
        int testCase = scan.nextInt();
        for (int i = 0; i < testCase; i++) {
            int count = scan.nextInt();
            int pointCase = scan.nextInt();
            int[] pointArray = new int[pointCase];
            for (int j = 0; j < pointCase; j++) {
                pointArray[j] = scan.nextInt();
            }
            System.out.println(Arrays.toString(pointArray));
            //누적합 

        }
    }
}
