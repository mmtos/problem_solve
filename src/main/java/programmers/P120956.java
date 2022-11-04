package programmers;

import java.util.Arrays;

/**
 * https://school.programmers.co.kr/learn/courses/30/lessons/120956
 *
 */
public class P120956 {
	//#정규표현식 #구현
	private static final String CAN_NOT_BABBLING = "CAN_NOT_BABBLING";
	private static final String CAN_BABBLING = "CAN_BABBLING";
	public static void main(String[] args) {
		String[] babbling ={"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
		String[] copyArr = Arrays.copyOf(babbling,babbling.length);
		String[] availableArr = { "aya", "ye", "woo", "ma"};
		while(true){
			if(isTraversalCompleted(copyArr)){
				break;
			}
			outer: for(int index=0 ; index < copyArr.length ; index ++){
				System.out.println(Arrays.toString(copyArr));
				String word = copyArr[index];
				if(word.equals(CAN_BABBLING) || word.equals(CAN_NOT_BABBLING)) continue;
				for(String available : availableArr){
					if(word.indexOf(available) == 0){
						copyArr[index] = word.substring(available.length());
						if(copyArr[index].equals("")){
							copyArr[index] = CAN_BABBLING;
						}else if(copyArr[index].indexOf(available) == 0){
							copyArr[index] = CAN_NOT_BABBLING;
						}
						continue outer;
					}
				}
				copyArr[index] = CAN_NOT_BABBLING;
			}
		}
		System.out.println(count(copyArr));
	}
	
	static boolean isTraversalCompleted(String[] babbling){
		for(String word : babbling){
			if(word.equals(CAN_BABBLING) || word.equals(CAN_NOT_BABBLING)){
				continue;
			}else{
				return false;
			}
		}
		return true;
	}

	static int count(String[] babbling){
		int answer = 0;
		for(String word : babbling){
			if(word.equals(CAN_BABBLING)){
				answer++;
			}
		}
		return answer;
	}
}
