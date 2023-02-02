package acmicpc;

import static java.util.Arrays.*;
import java.util.*;
import java.util.stream.Collectors;

public class P10871 {
/*
10 5
1 10 4 9 2 3 8 5 7 6

10 5
1 10 4 9 2 3 8 11 7 6

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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        X = scanner.nextInt();
        for(int i=0; i<N; i++){
            arr[i] = new Pair(scanner.nextInt(),i);
        }
        sort(arr,0,N, Comparator.comparing(Pair::getX));
        int index = binarySearch(arr,0,N,new Pair(X,1), Comparator.comparingInt(Pair::getX));
        System.out.println(Arrays.toString(copyOfRange(arr,0,index))); // 반구간 [ )
        List<Integer> answer = stream(copyOfRange(arr, 0, index)).sorted(Comparator.comparingInt(Pair::getY)).map(Pair::getX).collect(
                Collectors.toList());
        for(int i : answer){
            System.out.print(i + " ");
        }
    }
}
