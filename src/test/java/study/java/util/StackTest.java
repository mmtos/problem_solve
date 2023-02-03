package study.java.util;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

import java.util.EmptyStackException;
import java.util.Stack;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class StackTest {
    @Test
    @DisplayName("스택 예시")
    void t1(){
        Stack<Integer> S = new Stack<>();
        assertThatThrownBy(()-> S.pop()).isInstanceOf(EmptyStackException.class);
        S.push(3);
        S.push(4);
        assertThat(S.pop()).isEqualTo(4);
        assertThat(S.peek()).isEqualTo(3);
        S.push(5);
        S.push(6);
        S.push(7);
        assertThat(S.search(6)).isEqualTo(2); //1-based index from Top 위에서 2번째.
        assertThat(S.search(-7)).isEqualTo(-1); //못찾음
        assertThat(S.contains(5)).isTrue();
        assertThat(S.firstElement()).isEqualTo(3);
        System.out.println(S.firstElement()); // 가장 아래쪽으로도 접근가능
        S.removeElementAt(0); // 가장 아래쪽에서 삭제
        assertThat(S.firstElement()).isEqualTo(5);
    }
}
