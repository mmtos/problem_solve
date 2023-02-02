package study.java.lang;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.Arrays;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class StringTest {
    @Test
    void indexOf(){
        String target = "abadae";
        assertThat(target.indexOf("aba")).isEqualTo(0);
    }

    @Test
    void substring(){
        String target = "abadae";
        assertThat(target.substring(3)).isEqualTo("dae");
    }

    @Test
    void substring2(){
        String target = "aba";
        assertThat(target.substring(3)).isEqualTo("");
    }

    @Test
    @DisplayName("문자열을 char 배열로 변환하기")
    void t1(){
        String a = "abc";
        a.chars().forEach(i -> System.out.print((char) i));
        System.out.println(Arrays.toString(a.toCharArray()));
        assertThat(a.chars().count()).isEqualTo(3L);
    }
}
