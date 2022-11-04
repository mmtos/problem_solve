package programmers;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class P64063 {

	public static void main(String[] args) {
		// #DP
		//https://programmers.co.kr/learn/courses/30/lessons/64063
		
		//원하는 방이 비어있다면? Map이나 Set에 넣는다. 
		//비어있지 않다면 ? 방번호 1개씩 올리면서 다음 빈방 번호를 찾는다. 
		//O(n^2) : 고객 배열 반복 * 다음방 찾기위해 최악의 경우 k-1번 반복 
		//다음 방 검색이 문제. 연속된 비어있지 않은 방 중 마지막 방 + 1 반복계산을 줄여야함. 
		//1. 이미 차있는 방에 대해서 다음 차있는방까지의 거리를 저장한다.
		//2. 비어있는 방을 관리한다. 
		//3. 이미 차있는 방에 대해서 그 다음 빈방의 번호를 저장한다.
		
		
		// 다이나믹 프로그래밍.
		//방번호를 인덱스로 하는 배열 ? --> 배열이 공간만 차지하고 너무 많이 비어있게됨.
		Map<Long,Long> reserveMap = new HashMap<>(); //dictionary 처럼 사용하였음. 
		long k = 10; 
		long[] room_number = {1,3,4,1,3,1};
		long[] answer = new long[room_number.length];
		for(int i=0;i<answer.length;i++) {
			answer[i]=find(reserveMap,room_number[i]);
		}
		System.out.println(Arrays.toString(answer));
	}
	public static long find(Map<Long,Long> reserveMap, long want) {
		if(null == reserveMap.get(want)) {
			reserveMap.put(want, want+1);
			return want;
		}else {
			long noWantButEmpty = find(reserveMap,reserveMap.get(want));
			reserveMap.put(want, noWantButEmpty+1); // 중복 계산 방지를 위함.
			return noWantButEmpty;
		}
	}
}
