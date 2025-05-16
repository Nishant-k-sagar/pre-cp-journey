import java.util.concurrent.Semaphore; 
import java.util.Scanner; 
class ResourceManager { 
 private Semaphore semaphore; 
 public ResourceManager(int numResources, int maxResourcesPerProcess) { 
 semaphore = new Semaphore(numResources, true); 
 } 
 public void acquireResource(int processId) throws InterruptedException { 
 semaphore.acquire(); 
 System.out.println("Process " + processId + ": Acquired resource"); 
 } 
 public void releaseResource(int processId) { 
 semaphore.release(); 
 System.out.println("Process " + processId + ": Released resource"); 
 } 
} 
class Process extends Thread { 
 private int processId; 
 private ResourceManager resourceManager; 
 public Process(int processId, ResourceManager resourceManager) { 
 this.processId = processId; 
 this.resourceManager = resourceManager; 
 } 
 @Override
 public void run() { 
 try { 
 resourceManager.acquireResource(processId); 
 // Simulate process execution
 Thread.sleep(1000); 
 resourceManager.releaseResource(processId); 
 } catch (InterruptedException e) { 
 e.printStackTrace(); 
 } 
 } 
} 
public class p5 { 
 public static void main(String[] args) { 
 Scanner scanner = new Scanner(System.in); 
 // Input parameters
 System.out.print("Enter number of processes: "); 
 int numProcesses = scanner.nextInt(); 
 System.out.print("Enter number of resources: "); 
 int numResources = scanner.nextInt(); 
 System.out.print("Enter maximum resources a process can hold: "); 
 int maxResourcesPerProcess = scanner.nextInt(); 
 ResourceManager resourceManager = new ResourceManager(numResources, 
maxResourcesPerProcess); 
 for (int i = 1; i <= numProcesses; i++) { 
 Process process = new Process(i, resourceManager); 
 process.start(); 
 if(i==maxResourcesPerProcess){ 
 try { 
 Thread.sleep(1000); 
 } catch (InterruptedException ie) { 
 Thread.currentThread().interrupt(); 
 } 
 } 
 } 
 scanner.close(); 
 } 
} 