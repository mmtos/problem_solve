package study.java.util;

import static org.assertj.core.api.Assertions.assertThat;
import static org.assertj.core.api.Assertions.assertThatThrownBy;

import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class QueueTest {
    @Test
    @DisplayName("Queue API 사용연습")
    void t1(){
        // 상황에 따라 골라서 쓰자.
        Queue<Integer> Q = new ArrayDeque<>();
        Q.add(3);
        Q.add(4);
        // peek offer poll element
        assertThat(Q.peek()).isEqualTo(3);
        Q.offer(5);
        assertThat(Q.poll()).isEqualTo(3);
        assertThat(Q.element()).isEqualTo(4);
        Q.clear();
        assertThat(Q.poll()).isNull();
        assertThatThrownBy(() -> Q.element()).isInstanceOf(NoSuchElementException.class);
    }


    @Test
    @DisplayName("Queue API 사용연습2")
    void t2(){
        Queue<Integer> Q = new LinkedList<>();
        Q.add(3);
        Q.add(4);
        // peek offer poll element
        assertThat(Q.peek()).isEqualTo(3);
        Q.offer(5);
        assertThat(Q.poll()).isEqualTo(3);
        assertThat(Q.element()).isEqualTo(4);
        Q.clear();
        assertThat(Q.poll()).isNull();
        assertThatThrownBy(() -> Q.element()).isInstanceOf(NoSuchElementException.class);
    }
}
