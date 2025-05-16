import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

class ReaderWriter {
    private ReadWriteLock lock = new ReentrantReadWriteLock();
    private Lock readLock = lock.readLock();
    private Lock writeLock = lock.writeLock();

    public void read(int readerId) {
        try {
            readLock.lock();
            System.out.println("Reader " + readerId + ": Started reading");
            // Simulating reading process
            Thread.sleep(1000);
            System.out.println("Reader " + readerId + ": Finished reading");
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            readLock.unlock();
        }
    }

    public void write(int writerId) {
        try {
            writeLock.lock();
            System.out.println("Writer " + writerId + ": Started writing");
            // Simulating writing process
            Thread.sleep(2000);
            System.out.println("Writer " + writerId + ": Finished writing");
        } catch (InterruptedException e) {
            e.printStackTrace();
        } finally {
            writeLock.unlock();
        }
    }
}

class Reader extends Thread {
    private ReaderWriter readerWriter;
    private int readerId;

    public Reader(ReaderWriter readerWriter, int readerId) {
        this.readerWriter = readerWriter;
        this.readerId = readerId;
    }

    public void run() {
        readerWriter.read(readerId);
    }
}

class Writer extends Thread {
    private ReaderWriter readerWriter;
    private int writerId;

    public Writer(ReaderWriter readerWriter, int writerId) {
        this.readerWriter = readerWriter;
        this.writerId = writerId;
    }

    public void run() {
        readerWriter.write(writerId);
    }
}

public class Main {
    public static void main(String[] args) {
        ReaderWriter readerWriter = new ReaderWriter();
        int numReaders = 3;
        int numWriters = 2;

        // Start reader threads
        for (int i = 1; i <= numReaders; i++) {
            Reader reader = new Reader(readerWriter, i);
            reader.start();
        }

        // Start writer threads
        for (int i = 1; i <= numWriters; i++) {
            Writer writer = new Writer(readerWriter, i);
            writer.start();
        }
    }
}
