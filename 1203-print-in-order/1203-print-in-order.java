class Foo {
    // Semaphore to ensure second and third run in sequence
    private Semaphore secondReady = new Semaphore(0);  // Locks second method initially
    private Semaphore thirdReady = new Semaphore(0);   // Locks third method initially

    public Foo() {}
    
    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        secondReady.release();        // Unlock second method
    }

    public void second(Runnable printSecond) throws InterruptedException {
        // printSecond.run() outputs "second". Do not change or remove this line.
        secondReady.acquire();        // Wait until first() releases
        printSecond.run();            // prints "second"
        thirdReady.release();         // Unlock third method
    }

    public void third(Runnable printThird) throws InterruptedException {
        // printThird.run() outputs "third". Do not change or remove this line.
        thirdReady.acquire();         // Wait until second() releases
        printThird.run();     
    }
}

class Foo1 {

    // Wait for all threads to finish
    private CountDownLatch latch1 = new CountDownLatch(1);
    private CountDownLatch latch2 = new CountDownLatch(1);

    public Foo1() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        latch1.countDown(); // Allow second() to proceed
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latch1.await();     // Wait for first()
        // printSecond.run() outputs "second". Do not change or remove this line.
        printSecond.run();
        latch2.countDown(); // Allow third() to proceed
    }

    public void third(Runnable printThird) throws InterruptedException {
        latch2.await();     // Wait for second()
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}