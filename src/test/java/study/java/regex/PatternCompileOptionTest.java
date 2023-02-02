package study.java.regex;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.regex.Pattern;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import static org.assertj.core.api.Assertions.*;

/**
 *  flags – Match flags, a bit mask that may include
 *  CASE_INSENSITIVE,
 *  MULTILINE,
 *  DOTALL,
 *  UNICODE_CASE,
 *  CANON_EQ,
 *  UNIX_LINES,
 *  LITERAL,
 *  UNICODE_CHARACTER_CLASS
 *  and COMMENTS
 */
public class PatternCompileOptionTest {

    @Test
    @DisplayName("패턴 컴파일 옵션들 : 디폴트")
    void patternOptionTest(){
        String regExp = "axa";
        // flags – Match flags, a bit mask that may include CASE_INSENSITIVE, MULTILINE, DOTALL, UNICODE_CASE, CANON_EQ, UNIX_LINES, LITERAL, UNICODE_CHARACTER_CLASS and COMMENTS
        Pattern p1 = Pattern.compile(regExp, 0);
        Pattern p2 = Pattern.compile(regExp);
        assertThat(p1.flags()).isEqualTo(p2.flags());
    }

    @Test
    @DisplayName("패턴 컴파일 옵션들 : 대소문자 구분 X")
    void caseInsensitiveTest(){
        String regExp = "axa";
        String input = "Axa";
        Pattern p1 = Pattern.compile(regExp, Pattern.CASE_INSENSITIVE);
        Pattern p2 = Pattern.compile(regExp);
        assertThat(p1.matcher(input).matches()).isTrue();
        assertThat(p2.matcher(input).matches()).isFalse();
    }

    @Test
    @DisplayName("패턴 컴파일 옵션들 : 대소문자 구분 X - inline modifiers")
    void caseInsensitiveTest2(){
        String regExp = "(?i)axa";
        String input = "Axa";
        Pattern p1 = Pattern.compile(regExp);
        assertThat(p1.matcher(input).matches()).isTrue();
    }

    @Test
    @DisplayName("패턴 컴파일 옵션들 : 대소문자 구분 X")
    void caseInsensitiveTest3(){
        String regExp = "axa";
        String input = "Axa";
        Pattern p1 = Pattern.compile(regExp, Pattern.CASE_INSENSITIVE);
        Pattern p2 = Pattern.compile(regExp);
        assertThat(p1.matcher(input).matches()).isTrue();
        assertThat(p2.matcher(input).matches()).isFalse();
    }
}
