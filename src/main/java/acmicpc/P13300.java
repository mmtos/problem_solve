package acmicpc;

import java.io.*;
import java.util.*;

public class P13300 {
    static int[][] students = new int[2][7];
    static int N, K;
    public static void main(String[] args) throws Exception{
        //#배열
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            K = Integer.parseInt(st.nextToken());
            while(N-- > 0){
                st = new StringTokenizer(br.readLine());
                students[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] += 1;
            }
            int ans = 0;
            for(int i=0;i<2;i++){
                for(int j=1;j<7;j++){
                    while(students[i][j] > 0) {
                        students[i][j] -= K;
                        ans++;
                    }
                }
            }
            System.out.println(ans);
        }
    }
}
