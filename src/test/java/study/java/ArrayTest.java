package study.java;

import java.util.Arrays;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

public class ArrayTest {
    @Test
    void copy(){
        String[] arr = { "aya", "ye", "woo", "ma"};
        String[] copyArr = Arrays.copyOf(arr,arr.length);
        Assertions.assertThat(arr).isNotSameAs(copyArr);
        Assertions.assertThat(Arrays.equals(arr,copyArr)).isTrue();
    }
}
