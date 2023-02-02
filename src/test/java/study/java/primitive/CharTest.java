package study.java.primitive;

import static org.assertj.core.api.Assertions.assertThat;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class CharTest {


    @Test
    @DisplayName("char 사칙연산과 int")
    void t1(){
        int a = 'b' - 'c';
        assertThat(a).isEqualTo(-1);
        a = 'a';
        assertThat(a).isEqualTo(97);
    }

    @Test
    @DisplayName("int 배열에 char 넣기")
    void t2(){
        int[] arr = new int[100];
        arr['a'] = 3;

        char ac = 'a' + 1;
        arr[ac] = 4;
        assertThat(arr[97]).isEqualTo(3);
        assertThat(arr[98]).isEqualTo(4);
    }
}
