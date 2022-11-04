package programmers;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class P67256 {

	public static void main(String[] args) {
		//#구현
		//https://programmers.co.kr/learn/courses/30/lessons/67256
		//. x,1,x,3,4,x,6,7,x,9,*,#
		//2 3,1,0,1,2,1,2,3,2,3,4,4
		//5 2,2,1,2,1,0,1,2,1,2,3,3
		//8 1,3,2,3,2,1,2,1,0,1,2,2
		//0 0,4,3,4,3,2,3,2,1,2,1,1
//		Arrays.asList(0,1,0,1,2,0,2,3,0,3,4,4);
//		Arrays.asList(0,2,0,2,1,0,1,2,0,2,3,3);
//		Arrays.asList(0,3,0,3,2,0,2,1,0,1,2,2);
//		Arrays.asList(0,4,0,4,3,0,3,2,0,2,1,1);
		
		String answer = "";
		int[] numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
		String hand = "left";
		
        int leftPosition = 10; //최초포지션 *
        int rightPosition = 11; //최초포지션 #
        
        HashMap<Integer, List<Integer>> distanceMap = new HashMap<>();
        distanceMap.put(2,Arrays.asList(3,1,0,1,2,1,2,3,2,3,4,4));
        distanceMap.put(5,Arrays.asList(2,2,1,2,1,0,1,2,1,2,3,3));
        distanceMap.put(8,Arrays.asList(1,3,2,3,2,1,2,1,0,1,2,2));
        distanceMap.put(0,Arrays.asList(0,4,3,4,3,2,3,2,1,2,1,1));
        
        for(int number : numbers){
            if(number == 1 || number == 4 | number == 7){
                answer += "L";
                leftPosition = number;
            }else if(number == 3 || number == 6 | number == 9){
                answer += "R";
                rightPosition = number;
            }else{
                int leftDistance = distanceMap.get(number).get(leftPosition);
                int rightDistance = distanceMap.get(number).get(rightPosition);
                if(leftDistance < rightDistance) {
                	answer += "L";
                	leftPosition = number;
                }else if(leftDistance > rightDistance) {
                	answer += "R";
                	rightPosition = number;
                }else {
                	if("left".equals(hand)) {
                		answer += "L";
                		leftPosition = number;
                	}else if("right".equals(hand)) {
                		answer += "R";
                		rightPosition = number;
                	}
                }
            }
        }
        System.out.println(answer);
	}

}
