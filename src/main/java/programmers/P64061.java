package programmers;

import java.util.ArrayList;
import java.util.Stack;

public class P64061 {

	public static void main(String[] args) {
		// #미정 
		//		Stack<Integer> stack = new MyStack<>(10,0);
		//		Stack<String> stack2 = new MyStack<>(10,"0");
		//		test1(stack);
		//		((MyStack) stack).printAll();
		//		((MyStack) stack).print();
		//		
		// https://programmers.co.kr/learn/courses/30/lessons/64061
		// int 배열 + top 으로 스택구현
		
		// [1,2,3,4,5][6,7,8,9,10][11,12,13,14,15][16,17,18,19,20][21,22,23,24,25]
		// 각 배열의 첫번째 원소 : 1번 라인  위에서 부터 1,6,11,16,21, 뽑으면 1부터 나감. 뽑은 자리는 0으로 처리해서 두번 뽑지않게 하기.
		// 1번 라인에서 한 번 뽑고난 상태 ? 0,6,11,16,21
		// 각 배열의 두번째 원소 : 2번 라인 위에서부터 2,7,12,17,22
		int[][] board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
		int[] moves = {1,5,3,5,1,2,1,4};
		int[] stack = new int[1000];
		int top = -1;
		int answer = 0;
		for(int i=0;i<moves.length;i++) {
			int line = moves[i]-1;
			for(int j=0;j<board.length;j++) {
				if(board[j][line] != 0) {
					stack[++top] = board[j][line];
					board[j][line] = 0;
					if(top >= 1 && stack[top-1] == stack[top] ) {
						top -= 2;
						answer += 2;
					}
					break;
				}
			}
		}

		System.out.println(answer);
	}



	@SuppressWarnings("serial")
	private static class MyStack<T> extends Stack<T>{
		private int top;
		private int size;
		ArrayList<T> stack;

		MyStack(int size, T defaultValue){
			this.top = -1;
			this.size = size;
			stack = new ArrayList<T>(size);
			for(int i=0;i<size;i++) {
				stack.add(defaultValue);	
			}
		}

		void printAll() {
			System.out.println(stack);
		}
		void print() {
			if(top >=0) {
				System.out.println(stack.subList(0, top+1));	
			}else {
				System.out.println("no elements!!");
			}
		}

		public T pop() throws IllegalStateException{
			if(top <= 0) {
				throw new IllegalStateException("stack underflow");
			}
			return stack.get(top--);
		}
		public T push(T value) throws IllegalStateException{
			if(top >= size-1) {
				throw new IllegalStateException("stack overflow");
			}
			stack.add(++top, value);
			return value;
		}

		public T peek() {
			return stack.get(top);
		}
	}

	public static void test1(Stack<Integer> stack) {
		try{
			stack.pop();
		}catch(Exception e) {
			System.out.println(e.getMessage() + "...ignored...");
		}
		stack.push(55);
		stack.push(22);
		stack.push(33);
		stack.push(997);
		System.out.println(stack.pop());
		System.out.println(stack.peek());
	}
}
