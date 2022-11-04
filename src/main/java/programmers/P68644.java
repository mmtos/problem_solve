package programmers;

import java.util.Arrays;

public class P68644 {

	public static void main(String[] args) {
		// #미정
		// https://programmers.co.kr/learn/courses/30/lessons/68644
		// boolean[] memo를 통해 index를 원소로 하는 Set 자료구조 구현  
		int[] arr =	{2,1,3,4,1};
		boolean[] memo = new boolean[201];
		int size=0;
		for(int i=0;i<arr.length-1;i++) {
			for(int j=i+1;j<arr.length;j++) {
				if(!memo[arr[i]+arr[j]]) {
					size++;
				}
				memo[arr[i]+arr[j]] = true;
			}
		}
		int pushIndex = -1;
		int[] answer = new int[size];
		for(int i=0;i<memo.length;i++) {
			if(memo[i]) {
				answer[++pushIndex]=i;
			}
		}
		System.out.println(Arrays.toString(answer));
	}

}
