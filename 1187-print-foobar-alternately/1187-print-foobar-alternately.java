// Approach 1 - Low Level Synchronization APIs
// Approach 2 - Semaphores
// Approach 3 - AtomicInteger + Spin

// This is Approach 1
class FooBar1 {
    private final int n;

    // shared variable
    // start with foo
    private boolean fooTurn = true;

    public FooBar1(int n) {
        this.n = n;
    }

    // critical section
    public synchronized void foo(Runnable printFoo) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (!fooTurn) {
                wait();
            }

            // printFoo.run() outputs "foo". Do not change or remove this line.
            printFoo.run();
            fooTurn = false;
            notifyAll();
        }
    }

    // critical section
    public synchronized void bar(Runnable printBar) throws InterruptedException {

        for (int i = 0; i < n; i++) {
            while (fooTurn) {
                wait();
            }

            // printBar.run() outputs "bar". Do not change or remove this line.
            printBar.run();
            fooTurn = true;
            notifyAll();
        }
    }
}

class FooBar {
    private final int N;

    private Semaphore fooSemaphore = new Semaphore(1);
    private Semaphore barSemaphore = new Semaphore(0);

    public FooBar(int n) {
        this.N = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < N; i++) {
            fooSemaphore.acquire();
            printFoo.run();
            barSemaphore.release();
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < N; i++) {
            barSemaphore.acquire();
            printBar.run();
            fooSemaphore.release();
        }
    }

}
