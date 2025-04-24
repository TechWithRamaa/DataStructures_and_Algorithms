class Logger {
    /*
    \U0001f9e0 Expert Way to Think About It:
    Key Insight:
        We're not actually building a print system or waitlist/queue — we're only being asked to decide if a message should be printed right now based on the last time it was printed.
        So, we just need to track the last printed timestamp of each message.
    */
private:
    unordered_map<string, int> messageTimestamp;

public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        if (!messageTimestamp.count(message) ||
            timestamp - messageTimestamp[message] >= 10) {
            messageTimestamp[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */