package study.java.util;

import static java.util.stream.Collectors.toList;
import static org.assertj.core.api.Assertions.assertThat;

import java.util.List;
import java.util.stream.Stream;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class ListTest {
    @Test
    @DisplayName("리스트 생성")
    void t1(){
        List<Integer> list = Stream.generate(() -> 0).limit(100).collect(toList());
        assertThat(list).hasSize(100);
    }
}
