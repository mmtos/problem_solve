package study.java.regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class ForeGroundSearchTest {
	@Test
	@DisplayName("")
	void test() {
		// http://minsone.github.io/regex/regexp-lookaround
		// 1. 하위 표현식으로 어떤 지점을 찾는다. 하지만 소비되지는 않는다.
		// 2. 전방탐색의 경우 해당 지점 앞부분에서 실제 표현식과 일치하는 부분을 찾는다.
		// 2-1. 후방탐색의 경우 해당 지점 뒷부분에서 실제 표현식과 일치하는 부분을 찾는다.
		// 전방탐색(긍정) 연산자 (?=OO) OO는 하위표현식
		// 전방탐색(부정) 연산자 (?!OO) OO는 하위표현식
		// 후방탐색(긍정) 연산자 (?<=OO)
		String target = "ABC01: $23.45";
		Matcher m = Pattern.compile("(?<=\\$)[0-9.]+").matcher(target);
		while(m.find()) {
			System.out.println(m.group());
		}
		m.reset();
		
		System.out.println("target2");
		String target2 = "67.89-11.11$uu999999-ABC01: 2423456$23.45"; //- 빼보기
		m.reset(target2);
		//m.usePattern(Pattern.compile("(?=\\$)[0-9.]+")); //전방탐색 연산자 뒤에 표현식 사용 불가능(?)
		//m.usePattern(Pattern.compile("[0-9.]+(?=[A-Z]{1,})")); //전방긍정
		//m.usePattern(Pattern.compile("[0-9.]+(?=\\$)")); //전방긍정
		//m.usePattern(Pattern.compile("(?<=\\$)[0-9.]+")); //후방긍정
		while(m.find()) {
			StringBuffer sb = new StringBuffer();
			System.out.println(m.group());
			m.appendReplacement(sb, "#");
			System.out.println(sb);
			System.out.println(m.appendTail(sb));
		}
		
		String target3 = "11.11$22.22^"; //- 빼보기
		
		//m.usePattern(Pattern.compile("[0-9.]+(?![0-9\\$])")); //전방부정 (숫자도 아니고 $도 아닌 경우. 즉 위의 경우엔 ^인경우)
		m.usePattern(Pattern.compile("[0-9.]+(?!\\$)")); //전방부정 ($이 아닌 경우. 즉 위의 경우엔 #인경우)
		m.reset(target3);
		while(m.find()) {
			StringBuffer sb = new StringBuffer();
			System.out.println(m.group());
			m.appendReplacement(sb, "#");
			System.out.println(sb);
			System.out.println(m.appendTail(sb));
		}
		
		target3 = "I paid $30 nf40 f1 150or 100 apples,";
		//m.usePattern(Pattern.compile("\\b(?<!\\$)\\d+\\b")); //후방부정
		//m.usePattern(Pattern.compile("(?<!\\$)\\d+\\b")); //후방부정
		m.usePattern(Pattern.compile("(?<!\\$).*\\d+\\b")); //후방부정
		//m.usePattern(Pattern.compile("(?<!\\$)\\d+\\b")); //후방부정
		//m.usePattern(Pattern.compile("\\b")); //후방부정
		m.reset(target3);
		while(m.find()) {
			StringBuffer sb = new StringBuffer();
			System.out.println(m.group());
			m.appendReplacement(sb, "#");
			System.out.println(sb);
			System.out.println(m.appendTail(sb));
		}
		
		m.usePattern(Pattern.compile("[0-9.]+(?!\\$)")); //전방부정
	}

}
