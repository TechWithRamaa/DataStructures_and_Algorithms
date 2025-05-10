class FooBar {
    private final int n;

    // shared variable
    // start with foo
    private boolean fooTurn = true;

    public FooBar(int n) {
        this.n = n;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(!fooTurn) {
                wait();
            }

        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            fooTurn = false;
            notifyAll();
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(fooTurn) {
                wait();
            }
            
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            fooTurn = true;
            notifyAll();
        }
    }
}