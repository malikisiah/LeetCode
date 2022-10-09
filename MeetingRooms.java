import java.util.*;

public class MeetingRooms {

    public static void main(String[] args) {
        Interval interval = new Interval(50, 10);
        interval.start = 5;
    }

    public static boolean canAttendMeetings(List<Interval> intervals) {

        Collections.sort(intervals, (a,b) -> a.start - b.start);

        for (int i = 0; i+1 < intervals.size(); i++){
            if (intervals.get(i).end > intervals.get(i+1).start){
                return false;
            }
        }

        return true;
    }


}
