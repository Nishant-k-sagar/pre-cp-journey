import java.io.*; 
import java.util.Scanner; 
public class p10 { 
 public static void main(String[] args) throws IOException { 
 PipedInputStream in = new PipedInputStream(); 
 PipedOutputStream out = new PipedOutputStream(); 
 in.connect(out); 
 Scanner scanner = new Scanner(System.in); 
 System.out.print("Enter message to send from process 1 to process 2: 
"); 
 String message = scanner.nextLine(); 
 Process1 process1 = new Process1(out, message); 
 Thread thread1 = new Thread(process1); 
 thread1.start(); 
 Process2 process2 = new Process2(in); 
 Thread thread2 = new Thread(process2); 
 thread2.start(); 
 scanner.close(); 
 } 
} 
class Process1 implements Runnable { 
 private OutputStream out; 
 private String message; 
 public Process1(OutputStream out, String message) { 
 this.out = out; 
 this.message = message; 
 } 
 @Override
 public void run() { 
 try { 
 out.write(message.getBytes()); 
 out.close(); 
 } catch (IOException e) { 
 e.printStackTrace(); 
 } 
 } 
} 
class Process2 implements Runnable { 
 private InputStream in;