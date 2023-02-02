package acmicpc;

import java.util.*;
import java.io.*;
/*
*
4
a a
ab ba
ring gnir
newt twan

1
aa aa

1
aa a
* */
public class P11328 {

    public static void main(String[] args) throws Exception{
        //#배열
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out))
        ){
            int tc = Integer.parseInt(br.readLine());
            outer: while(tc-- > 0){
                int[][] arr = new int[2][30];
                StringTokenizer st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();
                a.chars().forEach(i-> arr[0][i-'a']+=1);
                b.chars().forEach(i-> arr[1][i-'a']+=1);
                for(int i='a';i<'z'+1;i++){
                    if(arr[0][i-'a'] != arr[1][i-'a']){
                        bw.write("Impossible\n"); bw.flush();
                        continue outer;
                    }
                }
                bw.write("Possible\n"); bw.flush();
            }
        }
    }
}
