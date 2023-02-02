package study.java.util;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.Arrays;
import java.util.stream.Collectors;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import study.java.struct.Pair;

public class ArraysCopyTest {
    @Test
    @DisplayName("배열 전체 복사")
    void t1(){
        String[] arr = { "aya", "ye", "woo", "ma"};
        String[] copyArr = Arrays.copyOf(arr,arr.length);
        assertThat(arr).isNotSameAs(copyArr);
        assertThat(Arrays.equals(arr,copyArr)).isTrue();
    }

    @Test
    @DisplayName("배열 일부 복사")
    void t2(){
        String[] arr = { "aya", "ye", "woo", "ma"};
        String[] copyArr = Arrays.copyOf(arr,2);
        assertThat(copyArr).containsExactly("aya", "ye");
    }

    @Test
    @DisplayName("배열 일부 복사 - 새로운 배열 길이가 더 긴 경우, String")
    void t3(){
        String[] arr = { "aya", "ye", "woo", "ma"};
        String[] copyArr = Arrays.copyOf(arr,6);
        assertThat(copyArr).hasSize(6);
        assertThat(copyArr).containsSequence(Arrays.asList("aya", "ye", "woo", "ma"));
        assertThat(copyArr).containsSubsequence(Arrays.asList("aya", "ye", "ma"));
        assertThat(copyArr).containsNull(); // null이 들어감
    }

    @Test
    @DisplayName("배열 일부 복사 - 새로운 배열 길이가 더 긴 경우, int")
    void t3_1(){
        int[] arr = { 1, 2, 3, 4};
        int[] copyArr = Arrays.copyOf(arr,6);
        System.out.println(Arrays.toString(copyArr));
        assertThat(copyArr).hasSize(6);
        assertThat(copyArr).containsExactly(1,2,3,4,0,0); // 기본값 0으로 들어감
    }

    @Test
    @DisplayName("배열 일부 복사 - 중간 부분만 복사, copyOfRange")
    void t3_2(){
        int[] arr = { 1, 2, 3, 4};
        int[] copyArr = Arrays.copyOfRange(arr,2,4);
        assertThat(copyArr).hasSize(2);
        assertThat(copyArr).containsExactly(3,4);
    }

    @Test
    @DisplayName("Arrays.copyOf는 얕은 복사")
    void t4(){
        Pair[] arr = new Pair[4];
        for(int i=0 ;i<4; i++) {
            arr[i] = new Pair(i,i);
        }
        Pair[] copyArr = Arrays.copyOf(arr,arr.length);
        assertThat(arr).isNotSameAs(copyArr);
        assertThat(arr[0]).isSameAs(copyArr[0]);
    }

    @Test
    @DisplayName("깊은 복사")
    void t5(){
        Pair[] arr = new Pair[4];
        for(int i=0 ;i<4; i++) {
            arr[i] = new Pair(i,i);
        }
        Pair[] copyArr = Arrays.stream(arr)
                .map(p -> new Pair(p.getX(),p.getY()))
                .toArray(size -> new Pair[size]);
        assertThat(arr[0]).isNotSameAs(copyArr[0]);
    }



}
