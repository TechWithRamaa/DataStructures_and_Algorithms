class Logger {
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