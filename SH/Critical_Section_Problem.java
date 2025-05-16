class SharedResource { 
    private int sharedVariable; 
    public SharedResource() { 
    this.sharedVariable = 0; 
    } 
    public synchronized void increment() { 
    sharedVariable++; 
    } 
    public synchronized int getValue() { 
    return sharedVariable; 
    } 
   } 
   class Resource { 
    private int sharedVariable; 
    public Resource() { 
    this.sharedVariable = 0; 
    } 
    public void increment() { 
    sharedVariable++; 
    } 
    public int getValue() { 
    return sharedVariable; 
    } 
   } 
   class IncrementThread extends Thread { 
    private Resource resource; 
    public IncrementThread(Resource resource) { 
    this.resource = resource; 
    } 
    @Override
    public void run() { 
    resource.increment(); 
    System.out.println(Thread.currentThread().getName() + ": Incremented 
   value to " + resource.getValue()); 
    } 
   } 
   class IncrementThreadSynchronized extends Thread { 
    private SharedResource resource; 
    public IncrementThreadSynchronized(SharedResource resource) { 
    this.resource = resource; 
    } 
    @Override
    public void run() { 
    synchronized (resource) { 
    try { 
    resource.wait(3000); 
    } catch (InterruptedException e) { 
    e.printStackTrace(); 
    return; 
    } 
    resource.increment(); 
    System.out.println(Thread.currentThread().getName() + ": 
   Incremented value to " + resource.getValue()); 
    } 
    } 
   } 
   public class p2 { 
    public static void main(String[] args) { 
    Resource resource1 = new Resource(); 
    Thread thread1 = new IncrementThread(resource1); 
    Thread thread2 = new IncrementThread(resource1); 
    thread1.start(); 
    thread2.start(); 
    SharedResource resource2 = new SharedResource(); 
    Thread thread3 = new IncrementThreadSynchronized(resource2); 
    Thread thread4 = new IncrementThreadSynchronized(resource2); 
    thread3.start(); 
    thread4.start(); 
    } 
   } 
   