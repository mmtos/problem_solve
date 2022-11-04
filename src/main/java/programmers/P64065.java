package programmers;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class P64065 {

	public static void main(String[] args) {
		// #미정
		//https://programmers.co.kr/learn/courses/30/lessons/64065
		// input : "{{2},{2,1},{2,1,3},{2,1,3,4}}" output : [2, 1, 3, 4]
		// input : "{{2},{2,1},{3,1,2},{4,1,2,3}}" output : [2, 1, 3, 4]
		// input을 어떤 자료구조에 넣을까. ArrayList. 배열의 크기는 ? ,로 split 하자
		// 문자열 길이로 "비교"해서 정렬. n번째 집합에 있는 원소는 n+1집합에 반드시 있기때문에 문자열길이도 항상 길어질것.
		// 길이가 1인 집합을 리스트에 집어 넣고 소거한다
		// 소거 종료시기는 ?
		// output 배열의 크기는?
		String input =  "{{2},{2,12},{2,12,3456},{2,12,3456,464}}";
		Map<String,Integer> countMap = new HashMap<>();
		// 숫자만 검색한다. Map을 만들어 카운트한다. 제일 많이 나오는게(위의 예제에선 2) 튜플의 첫번째 원소
		Matcher m = Pattern.compile("[0-9]+").matcher(input);
		while(m.find()) {
			//countMap.put(m.group(), countMap.get(m.group()) == null ? 1: countMap.get(m.group())+1);
			countMap.put(m.group(), countMap.getOrDefault(m.group(),0)+1);
			
		}
		System.out.println(countMap);
		System.out.println(countMap.size());
		int size = countMap.size();
		int[] answer = new int[size];
		for(String key : countMap.keySet()) {
			int value = countMap.get(key);
			answer[size-value] = Integer.parseInt(key);
		}
		
		int[] answer2 = countMap.entrySet().stream().sorted(Collections.reverseOrder(Map.Entry.comparingByValue())).map(Map.Entry::getKey).mapToInt(x->Integer.parseInt(x)).toArray();
		
		System.out.println(Arrays.toString(answer));
		System.out.println(Arrays.toString(answer2));
	}

}
