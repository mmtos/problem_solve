package study.java.regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class MatcherTest {
	@Test
	@DisplayName("")
	void test() {
		Pattern groupPattern = Pattern.compile("(c)(a)(t)");
		String str = "one cat two cats in the yard";
		Matcher m = groupPattern.matcher(str);
		//단계별 매칭 진행 : find
		//useFindMethod(m);

		//전체 매칭 진행
//		m.reset("cat");
//		if(m.matches()) {//전체 문자열이 일치할때만 true
//			groupMatchPrint(m);
//		}
		
		//검색범위 설정
		m.region(7, str.length());
		//m.region(7, 8);
		useFindMethod(m);
		System.out.println("using .... useTransparentBounds and matcher is reseted");
		m.reset();
		m.useTransparentBounds(true);
		useFindMethod(m);
	}

	private void useFindMethod(Matcher m) {
		StringBuffer sb = new StringBuffer("nothing");
		while (m.find()) {
			//m.appendReplacement(sb, "dog");
			groupMatchPrint(m);
			//System.out.println(sb.toString());
		}
		//m.appendTail(sb);
		System.out.println(sb.toString());
	}

	private void groupMatchPrint(Matcher m) {
		System.out.println("Group Count : " + m.groupCount());
		for(int i=0;i<=m.groupCount();i++) {
			System.out.println("group"+ i + " : " + m.group(i));
			System.out.println("group matching index : " + m.start(i) +" to " +m.end(i));
		}
	}

}
