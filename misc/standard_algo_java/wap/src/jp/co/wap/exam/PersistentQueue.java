package jp.co.wap.exam;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class PersistentQueue<E> {
	
	// Main idea to use another backup list (back) which stores values of elemtns along with front list which makes enqueue and dequeue in O(1) time

		private List<E> front;
		private List<E> back; 
	
		public PersistentQueue() {
			front = new ArrayList<E>();
			back  = new ArrayList<E>();
		}
		
		private PersistentQueue(List<E> front) {
			this.front = front;
		}
		

		public <T> PersistentQueue<E> enqueue(E e) {
			if (e == null) {
				throw new IllegalArgumentException();
				}
			
			List<E> front1 = new ArrayList<E>(back);
			front1.add(e);
			
			back.add(e);		
		    return new PersistentQueue<E>(front1);
		}
		
		
		public PersistentQueue<E> dequeue() {

			if (back.isEmpty()) {
				throw new NoSuchElementException();
			}
			
			List<E> clone = new ArrayList<E>(back);
			
			clone.remove(0);
			 back.remove(0);			
			
			return new PersistentQueue<E>(clone);
		}

		public E peek() {
			if (back.isEmpty()) {
				throw new NoSuchElementException();
			}
			return back.get(0);
		}

		public int size() {
			return back.size();
		}
	}
