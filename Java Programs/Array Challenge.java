
import java.util.*;
import java.text.SimpleDateFormat;
import java.time.*;
class Main{
	public static void main(String [] args) throws Exception{
	    
	    SimpleDateFormat format = new SimpleDateFormat("hh:mma");
	
		//String [] a1={"12:15PM-02:00PM","09:00AM-12:11PM","02:02PM-04:00PM"};
		String [] a1={"12:15PM-02:00PM","09:00AM-10:00AM","10:30AM-12:00PM"};
		
		// convert string to Date
		Date [][]date = new Date[a1.length][2];
		for(int i=0;i<a1.length;++i){
		    String[] temp = a1[i].split("-");
		    Date date1 = format.parse(temp[0]);
            Date date2 = format.parse(temp[1]);
            date[i][0] = date1;
            date[i][1] = date2;
		}
		// sort Date according to strating time
		Arrays.sort(date, (a, b) -> a[0].compareTo(b[0]));
		
		// find max difference
		long mx = 0;
		for(int i=0;i<a1.length-1;++i){
		    long temp = date[i+1][0].getTime() - date[i][1].getTime();
		    mx = mx>temp?mx:temp;
		}
		// print max difference
		System.out.println(convertSecondsToHMmSs(mx));
	}
	// function to convert millis to hh:mm
	public static String convertSecondsToHMmSs(long seconds) {
	    long millis = seconds % 1000;
        long second = (seconds / 1000) % 60;
        long minute = (seconds / (1000 * 60)) % 60;
        long hour = (seconds / (1000 * 60 * 60)) % 24;

        return String.format("%02d:%02d", hour, minute);
    }
}



