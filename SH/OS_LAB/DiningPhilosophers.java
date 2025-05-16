import java.util.concurrent.Semaphore;

public class DiningPhilosophers {
    private static final int NUM_PHILOSOPHERS = 5;
    private Semaphore[] chopsticks = new Semaphore[NUM_PHILOSOPHERS];

    public DiningPhilosophers() {
        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            chopsticks[i] = new Semaphore(1);
        }
    }

    public void eat(int philosopherId) throws InterruptedException {
        int leftChopstick = philosopherId;
        int rightChopstick = (philosopherId + 1) % NUM_PHILOSOPHERS;

        chopsticks[leftChopstick].acquire();
        chopsticks[rightChopstick].acquire();

        System.out.println("Philosopher " + philosopherId + " is eating");

        chopsticks[leftChopstick].release();
        chopsticks[rightChopstick].release();
    }

    public static void main(String[] args) {
        DiningPhilosophers dp = new DiningPhilosophers();

        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            final int philosopherId = i;
            new Thread(() -> {
                try {
                    while (true) {
                        dp.eat(philosopherId);
                        Thread.sleep(1000);
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }).start();
        }
    }
}