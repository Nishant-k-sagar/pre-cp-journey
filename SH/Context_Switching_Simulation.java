import java.util.*; 
class Process { 
 int pid; 
 int burstTime; 
 int remainingTime; 
 public Process(int pid, int burstTime) { 
 this.pid = pid; 
 this.burstTime = burstTime; 
 this.remainingTime = burstTime; 
 } 
} 
public class p1 { 
 public static void main(String[] args) { 
 Scanner scanner = new Scanner(System.in); 
 
 System.out.print("Number of processes: "); 
 int numProcesses = scanner.nextInt(); 
 List<Process> processes = new ArrayList<>(); 
 for (int i = 0; i < numProcesses; i++) { 
 System.out.print("Process ID (PID) for Process " + (i + 1) + ": 
"); 
 int pid = scanner.nextInt(); 
 System.out.print("Burst Time (BT) for Process " + (i + 1) + ": "); 
 int burstTime = scanner.nextInt(); 
 processes.add(new Process(pid, burstTime)); 
 } 
 System.out.print("Time Quantum (TQ): "); 
 int timeQuantum = scanner.nextInt(); 
 
 ///here we have used the round robin format for the time quantum 
excution of the 
 //processes..
 int currentTime = 0; 
 while (!processes.isEmpty()) { 
 for (int i = 0; i < processes.size(); i++) { 
 Process currentProcess = processes.get(i); 
 int remainingTime = currentProcess.remainingTime; 
 if (remainingTime > 0) { 
 int executeTime = Math.min(remainingTime, timeQuantum); 
 currentProcess.remainingTime -= executeTime; 
 currentTime += executeTime; 
 System.out.println("Executing Process " +
currentProcess.pid + " for " + executeTime + " units of time. Current Time: "
+ currentTime); 
 if (currentProcess.remainingTime == 0) { 
 processes.remove(i); 
 i--; 
 } 
 } 
 } 
 } 
 
 scanner.close(); 
 } 
} 