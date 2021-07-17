/*
 *
 * @author SidPro
 * @version 1.0
 *
 */

import java.util.Scanner;
class TestStopWatch{
	public static void main(String []args){
		Scanner scan= new Scanner(System.in);
		StopWatch clock = new StopWatch();
		System.out.println("Enter long number: ");
		long n = scan.nextLong();
		clock.start();
		System.out.println("Clock started");
		System.out.println("loop "+n+" started");
		for(long i=0L;i<n;++i){System.out.print(i);}
		System.out.println();
		System.out.println("loop "+n+" Ended");
		clock.stop();
		System.out.println("Clock Ended");
		System.out.println("Elapsed Time :"+clock.getElapsedTime()+" Milli seconds");
	}
}

class StopWatch{
	private long StartTime;
	private long EndTime;
	
	StopWatch(){
		this.StartTime = System.currentTimeMillis();
	}
	void start(){
		this.StartTime = System.currentTimeMillis();
	}
	void stop(){
		this.EndTime = System.currentTimeMillis();
	}
	long getElapsedTime(){
		return (EndTime - StartTime);
	}
} 