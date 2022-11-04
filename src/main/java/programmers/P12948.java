package programmers;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class P12948 {

	public static void main(String[] args) {
		//#정규표현식
		// https://programmers.co.kr/learn/courses/30/lessons/12948
		// 정규식으로 폰번호 가리기 : 뒤에 4개만 남길것
		
		String phoneNumber= "12345672329846912881";
		int size = phoneNumber.length();
		Matcher m = Pattern.compile("[0-9]{1}").matcher(phoneNumber);
		StringBuffer sb = new StringBuffer();
		int remaining = size;
		while(m.find() && remaining>4) {
			m.appendReplacement(sb, "*");
			remaining--;
		}
		m.appendTail(sb);
		System.out.println(sb);
		
		//다른방법
		String lastFour = phoneNumber.substring(phoneNumber.length()-4);
		String first = phoneNumber.substring(0,phoneNumber.length()-4);
		System.out.println(lastFour);
		System.out.println(first);
		for(int i=0;i<first.length();i++) {
			lastFour = "*"+lastFour;
		}
		System.out.println(lastFour);
	}

}
