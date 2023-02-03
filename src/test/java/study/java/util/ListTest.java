package study.java.util;

import static java.util.stream.Collectors.toList;
import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;

import java.util.LinkedList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
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

    @Test
    @DisplayName("연결 리스트 API 연습")
    void t2(){
        LinkedList<Integer> list = IntStream.range(1,11).boxed().collect(Collectors.toCollection(LinkedList::new));
        assertThat(list).hasSize(10);

        // add
        list.add(2,-5);
        assertThat(list.get(2)).isEqualTo(-5);

        list.addFirst(11);
        list.addLast(22);

        // element는 맨앞 원소 가져오기
        assertThat(list.element()).isEqualTo(11);
        assertThat(list.getFirst()).isEqualTo(11);
        assertThat(list.getLast()).isEqualTo(22);

        //remove
        list.removeLast();
        list.removeFirst();
        list.remove(2);
        assertThat(list).hasSize(10);

        // pop, poll은 맨앞쪽에서 제거
        assertThat(list.poll()).isEqualTo(1);
        assertThat(list).hasSize(9);
        assertThat(list.pop()).isEqualTo(2);
        assertThat(list).hasSize(8);

        // peek
        assertThat(list.peek()).isEqualTo(3);
        assertThat(list.peekFirst()).isEqualTo(3);
        assertThat(list.peekLast()).isEqualTo(10);

        list.push(2);
        list.push(1);
        list.offerLast(11);
        list.offerFirst(0);

        // 리스트 비우기
        list.clear();
        assertThat(list).isEmpty();
        assertThrows(NoSuchElementException.class,() -> list.element());
        assertThrows(NoSuchElementException.class,() -> list.getFirst());
        assertThrows(NoSuchElementException.class,() -> list.getLast());
        assertThrows(NoSuchElementException.class,() -> list.pop());
        assertThat(list.poll()).isNull();
        assertThat(list.peek()).isNull();
        assertThat(list.peekFirst()).isNull();
        assertThat(list.peekLast()).isNull();
    }
}
