mport java.util.Scanner; 
class MyThread extends Thread { 
 public MyThread(String name, int priority) { 
 super(name); 
 setPriority(priority); // Set the priority of the thread
 try { 
 Thread.sleep( 1000); 
 } catch (InterruptedException ie) { 
 Thread.currentThread().interrupt(); 
 } 
 } 
 @Override
 public void run() { 
 System.out.println(Thread.currentThread().getName() + " running..."); 
 } 
} 
public class p9 { 
 public static void main(String[] args) { 
 Scanner scanner = new Scanner(System.in); 
 System.out.println("Enter priority for Thread 1:"); 
 int priority1 = scanner.nextInt(); 
 System.out.println("Enter priority for Thread 2:"); 
 int priority2 = scanner.nextInt(); 
 System.out.println("Enter priority for Thread 3:"); 
 int priority3 = scanner.nextInt(); 
 MyThread thread1 = new MyThread("Thread 1", priority1); 
 MyThread thread2 = new MyThread("Thread 2", priority2); 
 MyThread thread3 = new MyThread("Thread 3", priority3); 
 thread1.start(); 
 thread2.start(); 
 thread3.start(); 
 scanner.close(); 
 } 
}