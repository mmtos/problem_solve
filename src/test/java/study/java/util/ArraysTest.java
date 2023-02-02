package study.java.util;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.Arrays;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class ArraysTest {

    @Test
    @DisplayName("이분탐색 - 값이 있는 경우")
    void t1(){
        int[] arr = { 1, 3, 5, 7, 9};
        int foundIdx = Arrays.binarySearch(arr,5);
        assertThat(foundIdx).isEqualTo(2);
    }

    @Test
    @DisplayName("이분탐색 - 값이 없는 경우")
    void t2(){
        int[] arr = { 1, 3, 5, 7, 9 };
        int foundIdx = Arrays.binarySearch(arr,18);
        assertThat(foundIdx).isEqualTo(-6);
        foundIdx = Arrays.binarySearch(arr,11);
        assertThat(foundIdx).isEqualTo(-6);
        foundIdx = Arrays.binarySearch(arr,8);
        assertThat(foundIdx).isEqualTo(-5);
        foundIdx = Arrays.binarySearch(arr,6);
        assertThat(foundIdx).isEqualTo(-4); // -(-4+1)번째 인덱스로 insert 할 수 있음
        foundIdx = Arrays.binarySearch(arr,4);
        assertThat(foundIdx).isEqualTo(-3);
        foundIdx = Arrays.binarySearch(arr,2);
        assertThat(foundIdx).isEqualTo(-2); // -2 + 1 해주면 ? 들어갈 자리임.
        foundIdx = Arrays.binarySearch(arr,0);
        assertThat(foundIdx).isEqualTo(-1);
        foundIdx = Arrays.binarySearch(arr,-5);
        assertThat(foundIdx).isEqualTo(-1);
    }


}
