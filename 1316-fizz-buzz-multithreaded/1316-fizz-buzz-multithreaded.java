class FizzBuzz {
    private int n;
    private int i = 1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        while (i <= n) {
            while (i <= n && (i % 3 != 0 || i % 5 == 0)) wait();
            if (i > n) break;
            printFizz.run();
            i++;
            notifyAll();
        }
    }

    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        while (i <= n) {
            while (i <= n && (i % 5 != 0 || i % 3 == 0)) wait();
            if (i > n) break;
            printBuzz.run();
            i++;
            notifyAll();
        }
    }

    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (i <= n) {
            while (i <= n && (i % 15 != 0)) wait();
            if (i > n) break;
            printFizzBuzz.run();
            i++;
            notifyAll();
        }
    }

    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        while (i <= n) {
            while (i <= n && (i % 3 == 0 || i % 5 == 0)) wait();
            if (i > n) break;
            printNumber.accept(i);
            i++;
            notifyAll();
        }
    }
}
