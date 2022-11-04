package acmicpc;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class P1517 {
    private static final String pNum = "P1517";
    private static long answer = 0;

    public static void main(String[] args) throws Exception {
        // #분할정복
        String inputPath = "";
        try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input_directory")))){
            inputPath = br.readLine();
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(inputPath + pNum)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(Arrays.toString(arr));
        //실제로 버블정렬할 경우 n^2이 걸린다. 통과 불가능
        //머지소트 과정에서 inversion(i<j && arr[i]>arr[j]의 개수를 셀 수 있다.)
        //분할정복 문제인 이유? : 머지소트가 바로 분할정복을 이용한 것임. 큰 문제의 로직을 작은 문제에도 그대로 적용 가능함. 
        //작은 문제의 해결이 또 다른 작은 문제에 영향을 미치지 않기때문에 그렇지않은 DP문제(ex 최적부분구조, 하위문제들이 중복되는 경우, 피보나치)와는 구분지을 수 있다.
        //분할정복은 거의 재귀를 사용하지만. DP는 일반 반복문으로 하는게 편한경우도 있다.
        mergeSortToCountInversion(arr, 0, arr.length - 1);
        System.out.println(Arrays.toString(arr));
        System.out.println(answer);
    }

    static void mergeSortToCountInversion(int[] arr, int start, int end) {
        mergeSort(arr, start, end);
    }

    static void mergeSort(int[] arr, int start, int end) {
        int mid = (start + end) / 2;
        if (mid == end) {
            return;
        }
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        int[] temp = new int[end - start + 1];
        int index1 = start;
        int index2 = mid + 1;
        int temp_i = 0;
        while (index1 <= mid && index2 <= end) {
            if (arr[index1] <= arr[index2]) {
                temp[temp_i++] = arr[index1++];
            } else {
                //오른쪽 배열에서 temp로 들어오는 경우 왼쪽에 남은 원소의 개수를 더해주자. 단 같은 경우는 제외
                temp[temp_i++] = arr[index2++];
                answer += mid - index1 + 1;
            }
        }
        while (index1 <= mid) {
            temp[temp_i++] = arr[index1++];
        }
        while (index2 <= end) {
            temp[temp_i++] = arr[index2++];
        }

        for (int i = 0; i < temp.length; i++) {
            arr[start + i] = temp[i];
        }
    }

}
