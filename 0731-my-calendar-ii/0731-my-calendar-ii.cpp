
class MyCalendarTwo {
public:
    bool book(int start, int end) {
        timeline[start]++; // Tentatively add the new event to the calendar.
        timeline[end]--;

        int activeEvents = 0;

        for (const auto& [_, count] : timeline) {
            activeEvents += count;

            if (activeEvents > 2) {

                if (--timeline[start] == 0)
                    timeline.erase(start); // optimization to keep the storage clean ie only active events

                if (++timeline[end] == 0)
                    timeline.erase(end); // optimization to keep the storage clean ie only active events

                return false;
            }
        }

        return true;
    }

private:
    map<int, int> timeline;
};