package acmicpc;

import static java.util.Arrays.*;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class P10871 {
/*
10 5
1 10 4 9 2 3 8 5 7 6

10 5
1 10 4 9 2 3 8 11 7 6

10 5
1 10 4 9 5 5 8 11 7 5

10 0
1 10 4 9 2 3 8 5 7 6

10 11
1 10 4 9 2 3 8 5 7 6

10 15
1 10 4 9 2 3 8 5 7 6
*/
    static class Pair{
        int x,y;
        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }
        public int getY(){
            return y;
        }

        @Override
        public String toString() {
            return "Pair{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    static int N,X;
    static final int MAX_N = 100001;
    static Pair[] arr = new Pair[MAX_N];

    private static void sol1(){
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        X = scanner.nextInt();
        for(int i=0; i<N; i++){
            arr[i] = new Pair(scanner.nextInt(),i);
        }
        sort(arr,0,N, Comparator.comparing(Pair::getX));
        int index = binarySearch(arr,0,N,new Pair(X,1), Comparator.comparingInt(Pair::getX));
        if(index < 0) index = -index-1;
        while(index > 0 && arr[index-1].getX() == X) index--;
        //System.out.println(Arrays.toString(copyOfRange(arr,0,index))); // 반구간 [ )
        List<Integer> answer = stream(copyOfRange(arr, 0, index)).sorted(Comparator.comparingInt(Pair::getY)).map(Pair::getX).collect(
                Collectors.toList());
        for(int i : answer){
            System.out.print(i + " ");
        }
    }

    private static void sol2(){
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ){
            StringTokenizer tks = new StringTokenizer(br.readLine()," ");
            N = Integer.parseInt(tks.nextToken());
            X = Integer.parseInt(tks.nextToken());
            tks = new StringTokenizer(br.readLine()," ");
            for(int i=0; i<N; i++){
                arr[i] = new Pair(Integer.parseInt(tks.nextToken()),i);
            }

            sort(arr,0,N, Comparator.comparing(Pair::getX));
            int index = binarySearch(arr,0,N,new Pair(X,1), Comparator.comparingInt(Pair::getX));
            if(index < 0) index = -index-1;
            while(index > 0 && arr[index-1].getX() == X) index--;
            List<Integer> answer = stream(copyOfRange(arr, 0, index)).sorted(Comparator.comparingInt(Pair::getY)).map(Pair::getX).collect(
                    Collectors.toList());
            for(int i : answer){
                bw.write(i + " ");
                bw.flush();
            }
        }catch (IOException e){
            throw new RuntimeException();
        }
    }

    private static void sol3() throws Exception{
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        ){
            StringTokenizer tks = new StringTokenizer(br.readLine()," ");
            N = Integer.parseInt(tks.nextToken());
            X = Integer.parseInt(tks.nextToken());
            tks = new StringTokenizer(br.readLine()," ");
            for(int i=0; i<N; i++){
                int t = Integer.parseInt(tks.nextToken());
                if(t<X) bw.write(Integer.parseInt(tks.nextToken()) + " ");
            }
            bw.flush();
        }
    }

    public static void main(String[] args) throws Exception{
        // #입출력
        sol3();
    }
}
