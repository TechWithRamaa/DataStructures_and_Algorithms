class H2O {
    private Semaphore hydrogenSem = new Semaphore(2);
    private Semaphore oxygenSem = new Semaphore(1);
    private CyclicBarrier barrier = new CyclicBarrier(3); // waits for 3 threads

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hydrogenSem.acquire(); // allow only 2 hydrogens per group
        try {
            barrier.await(); // wait until 3 parties (2H + 1O) arrive
            releaseHydrogen.run(); // print "H"
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            hydrogenSem.release(); // release permit for next batch
        }
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oxygenSem.acquire(); // allow only 1 oxygen per group
        try {
            barrier.await(); // wait until 3 parties arrive
            releaseOxygen.run(); // print "O"
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            oxygenSem.release(); // release permit for next batch
        }
    }
}