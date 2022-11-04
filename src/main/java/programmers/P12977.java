package programmers;

import java.util.ArrayList;
import java.util.Arrays;

public class P12977 {
	
	static ArrayList<Integer> primes; 
	static int answer;
	public static void main(String[] args) {
		// #소수
		//https://programmers.co.kr/learn/courses/30/lessons/12977
		// # 에라토스테네스의 체. 걸러내는 반복 횟수를 최대값의 1/2가 아니라 최대값의 sqrt까지만 반복해도 된다고 함. 
		// # 조합 구현(재귀 방식) visited : 선택여부 기록, depth : 현재 선택여부를 고려하는 index, k 더 골라야할 원소의 갯수
		
//		int limit = 200000;
//		long start=0;
//		start = System.currentTimeMillis();
//		System.out.println(Arrays.toString(initPrimeNumber(limit)));
//		System.out.println(System.currentTimeMillis() - start);
//		
		primes = initPrimeNumber2(3000);
		int[] nums = {1,2,7,6,4};
		boolean[] visited = new boolean[nums.length]; 
		combi(nums,visited,0,3);
		System.out.println(answer);
		System.out.println(combi2(nums,visited,0,3));
//		start = System.currentTimeMillis();
//		System.out.println(Arrays.toString(initPrimeNumberBadWay(limit)));
//		System.out.println(System.currentTimeMillis() - start);
		
	}
	public static void combi(int[] nums, boolean[] visited, int depth, int k) {
		if(k == 0) {
			int sum = 0;
			for(int i=0 ; i<nums.length;i++ ) {
				if(visited[i]) {
					System.out.print(nums[i]+" ");
					sum+=nums[i];
					
				}
			}
			System.out.println();
			if(primes.contains(sum)) answer++;
			return;
		}
		if(depth == nums.length ) {
			return;
		}
		visited[depth]=true;
		combi(nums,visited,depth+1,k-1);
		visited[depth]=false;
		combi(nums,visited,depth+1,k);
		
	}
	
	public static int combi2(int[] nums, boolean[] visited, int depth, int k) {
		if(k == 0) {
			int sum = 0;
			for(int i=0 ; i<nums.length;i++ ) {
				if(visited[i]) {
					System.out.print(nums[i]+" ");
					sum+=nums[i];
					
				}
			}
			System.out.println();
			if(primes.contains(sum)) {
				return 1;
			}
			return 0;
		}
		if(depth == nums.length ) {
			return 0 ;
		}
		visited[depth]=true;
		int include = combi2(nums,visited,depth+1,k-1);
		visited[depth]=false;
		int exclude = combi2(nums,visited,depth+1,k);
		return include +exclude;
	}
	
	public static int[] initPrimeNumber(int upperLimit){
		ArrayList<Integer> arr = new ArrayList<>();
		boolean[] isPrimeArr = new boolean[upperLimit+1];
		//모두 소수라고 일단 가정
		Arrays.fill(isPrimeArr, true);
		//에라체 구현하기
		isPrimeArr[0]=false;
		isPrimeArr[1]=false;
		int pointer=2;
		while(pointer <= upperLimit/2) {
			if(!isPrimeArr[pointer]) {
				pointer++;
			}else {
				for(int i=2;pointer*i<=upperLimit;i++) {
					isPrimeArr[pointer*i]=false;
				}
				pointer++;
			}
		}
		System.out.println(Arrays.toString(isPrimeArr));
		for(int i=0;i<isPrimeArr.length;i++) {
			if(isPrimeArr[i]) {
				arr.add(i);
			}
		}
		
		return arr.stream().sorted().mapToInt(Integer::intValue).toArray();
    }
	public static ArrayList<Integer> initPrimeNumber2(int upperLimit){
		ArrayList<Integer> arr = new ArrayList<>();
		boolean[] isPrimeArr = new boolean[upperLimit+1];
		//모두 소수라고 일단 가정
		Arrays.fill(isPrimeArr, true);
		//에라체 구현하기
		isPrimeArr[0]=false;
		isPrimeArr[1]=false;
		int pointer=2;
		while(pointer <= upperLimit/2) {
			if(!isPrimeArr[pointer]) {
				pointer++;
			}else {
				for(int i=2;pointer*i<=upperLimit;i++) {
					isPrimeArr[pointer*i]=false;
				}
				pointer++;
			}
		}
		System.out.println(Arrays.toString(isPrimeArr));
		for(int i=0;i<isPrimeArr.length;i++) {
			if(isPrimeArr[i]) {
				arr.add(i);
			}
		}
		
		return arr;
    }
	public static int[] initPrimeNumberBadWay(int upperLimit){
		ArrayList<Integer> arr = new ArrayList<>();
		boolean[] isPrimeArr = new boolean[upperLimit+1];
		//모두 소수라고 일단 가정
		Arrays.fill(isPrimeArr, true);
		isPrimeArr[0]=false;
		isPrimeArr[1]=false;
		
		for(int i=2;i<upperLimit;i++) {
			for(int j=2;j<i;j++) {
				if(i%j == 0) {
					isPrimeArr[i]=false;
					break;
				}
			}
		}
		
		System.out.println(Arrays.toString(isPrimeArr));
		for(int i=0;i<isPrimeArr.length;i++) {
			if(isPrimeArr[i]) {
				arr.add(i);
			}
		}
		
		return arr.stream().sorted().mapToInt(Integer::intValue).toArray();
    }
}
