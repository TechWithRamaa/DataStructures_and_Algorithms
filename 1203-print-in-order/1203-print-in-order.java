class Foo {

    private CountDownLatch latch1 = new CountDownLatch(1);
    private CountDownLatch latch2 = new CountDownLatch(1);

    public Foo() {
        
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