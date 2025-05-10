class DiningPhilosophers {

    Semaphore[] semaphores = new Semaphore[5];

    public DiningPhilosophers() {
        for (int i = 0; i < semaphores.length; i++) {
            semaphores[i] = new Semaphore(0);
        }
        semaphores[0].release(); // start with zeroth philosopher
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        semaphores[philosopher].acquire(); // acquire for current philosopher
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        semaphores[(philosopher + 1) % 5].release(); // release for next philosopher
    }
}