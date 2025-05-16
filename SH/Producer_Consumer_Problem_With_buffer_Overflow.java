import java.util.*; 
class BoundedBuffer { 
 private LinkedList<Integer> buffer; 
 private int capacity; 
 public BoundedBuffer(int capacity) { 
 this.capacity = capacity; 
 this.buffer = new LinkedList<>(); 
 } 
 public synchronized void produce(int item) throws InterruptedException { 
 while (buffer.size() == capacity) { 
 System.out.println("Buffer full, producer waits"); 
 wait(); 
 } 
 buffer.add(item); 
 System.out.println("Produced: " + item); 
 notifyAll(); 
 } 
 public synchronized int consume() throws InterruptedException { 
 while (buffer.isEmpty()) { 
 System.out.println("Buffer empty, consumer waits"); 
 wait(); 
 } 
 int item = buffer.remove(); 
 System.out.println("Consumed: " + item); 
 notifyAll(); 
 return item; 
 } 
} 
class Producer extends Thread { 
 private BoundedBuffer buffer; 
 private int itemsToProduce; 
 public Producer(BoundedBuffer buffer, int itemsToProduce) { 
 this.buffer = buffer; 
 this.itemsToProduce = itemsToProduce; 
 } 
 @Override
 public void run() { 
 for (int i = 1; i <= itemsToProduce; i++) { 
 try { 
 buffer.produce(i); 
 Thread.sleep(1000); 
 } catch (InterruptedException e) { 
 e.printStackTrace(); 
 } 
 } 
 } 
} 
class Consumer extends Thread { 
 private BoundedBuffer buffer; 
 private int itemsToConsume; 
 public Consumer(BoundedBuffer buffer, int itemsToConsume) { 
 this.buffer = buffer; 
 this.itemsToConsume = itemsToConsume; 
 } 
 @Override
 public void run() { 
 for (int i = 0; i < itemsToConsume; i++) { 
 try { 
 buffer.consume(); 
 Thread.sleep(5000); // Consumption delay
 } catch (InterruptedException e) { 
 e.printStackTrace(); 
 } 
 } 
 } 
} 
public class p3 { 
 public static void main(String[] args) { 
 Scanner scanner = new Scanner(System.in); 
 
 System.out.print("Buffer Capacity: "); 
 int bufferCapacity = scanner.nextInt(); 
 System.out.print("Items to be produced: "); 
 int itemsToProduce = scanner.nextInt(); 
 int consumptionDelay = 1000; // 1 second
 BoundedBuffer buffer = new BoundedBuffer(bufferCapacity); 
 Producer producer = new Producer(buffer, itemsToProduce); 
 Consumer consumer = new Consumer(buffer, itemsToProduce); 
 producer.start(); 
 consumer.start(); 
 } 
} 