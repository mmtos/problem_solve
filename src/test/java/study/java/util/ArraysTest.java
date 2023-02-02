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

    @Test
    @DisplayName("이분탐색 - 값이 있는 경우 + 중복된 원소가 있는 경우")
    void t3(){
        int[] arr = { 1, 3, 5, 5, 5, 7, 9};
        int foundIdx = Arrays.binarySearch(arr,5);
        assertThat(foundIdx).isEqualTo(3); // 3개 중에 어떤게 검색될 지 모름
    }

    @Test
    @DisplayName("이분탐색 - 값이 있는 경우 + 중복된 원소가 있는 경우")
    void t3_1(){
        int[] arr = { 1, 3, 5, 5, 5, 5, 5, 5, 7, 9};
        int foundIdx = Arrays.binarySearch(arr,5);
        assertThat(foundIdx).isEqualTo(4); // 6개 중에 어떤게 검색될 지 모름
    }


    @Test
    @DisplayName("배열 초기화하기")
    void t4(){
        int[] arr = new int[100];
        Arrays.fill(arr,1);
        assertThat(arr).containsOnly(1);
    }
}
