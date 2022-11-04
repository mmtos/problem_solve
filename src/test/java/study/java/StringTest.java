package study.java;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

public class StringTest {
    @Test
    void indexOf(){
        String target = "abadae";
        Assertions.assertThat(target.indexOf("aba")).isEqualTo(0);
    }

    @Test
    void substring(){
        String target = "abadae";
        Assertions.assertThat(target.substring(3)).isEqualTo("dae");
    }
    @Test
    void substring2(){
        String target = "aba";
        Assertions.assertThat(target.substring(3)).isEqualTo("");
    }
}
