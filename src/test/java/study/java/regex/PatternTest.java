package study.java.regex;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.List;
import java.util.regex.Pattern;
import org.assertj.core.util.Lists;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import static org.assertj.core.api.Assertions.*;
public class PatternTest {


    @Test
    @DisplayName("바로 match 테스트도 가능하다")
    void matchDirectlyTest(){
        String regExp = "axa";
        String input = "aaxaa";
        assertThat(Pattern.matches(regExp,input)).isFalse();
    }

    @Test
    @DisplayName("정규표현식 패턴에서 특수문자를 escape하고 싶을때 quote를 사용")
    void quoteTest(){
        //https://www.baeldung.com/java-pattern-quote
        String regExp = "$10";
        String literalizedRegExp = Pattern.quote(regExp);
        List<String> targets = Lists.list("$10","$20","$30");
        long matches = targets.stream()
                .filter(Pattern.compile(literalizedRegExp).asPredicate())
                .count();
        assertThat(matches).isEqualTo(1L);
    }

    @Test
    @DisplayName("quote를 사용하지 않은 경우")
    void noQuoteTest(){
        String regExp = "$10";
        List<String> targets = Lists.list("$10","$20","$30");
        long matches = targets.stream()
                .filter(Pattern.compile(regExp).asPredicate())
                .count();
        assertThat(matches).isEqualTo(0L);
    }

}
